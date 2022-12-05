#include <iostream>
#include <string>
#include <algorithm>
#include "profile.h"
#include "network.h"

Network::Network() {
    numUsers = 0;
    for (int id1 = 0; id1 < MAX_USERS; id1++) {
        for (int id2 = 0; id2 < MAX_USERS; id2++) {
            following[id1][id2] = false;
        }
    }
}

int Network::findID(std::string usrn) {
    int ID = -1;
    for (int i = 0; i < numUsers; i++) {
        //std::cout << profiles[i].getUsername() << std::endl;
        if (profiles[i].getUsername() == usrn) {
            ID = i;
        }
    }
    return ID;
}

bool Network::addUser(std::string usrn, std::string dspn) {
    Profile temp(usrn, dspn);

    bool uniqueID = (findID(usrn) == -1);
    bool isAlphaNumeric = std::all_of(usrn.begin(), usrn.end(), ::isalnum);
    if (uniqueID && isAlphaNumeric && numUsers < MAX_USERS) {
        profiles[numUsers] = temp;
        numUsers++;
        return true;
    }
    return false;
}

// Make 'usrn1' follow 'usrn2' (if both usernames are in the network).
// return true if success (if both usernames exist), otherwise return false
bool Network::follow(std::string usrn1, std::string usrn2) {
    bool uniqueID1 = (findID(usrn1) != -1); //is true if usrn1 exists
    bool uniqueID2 = (findID(usrn2) != -1); //is true if usrn2 exists
    if (uniqueID1 && uniqueID2) {
        following[findID(usrn1)][findID(usrn2)] = true;
        return true;
    }
    return false;
}

// Print Dot file (graphical representation of the network)
void Network::printDot() {
    std::cout << "digraph  {" << std::endl;
    //print all the users in the array
    for (int i = 0; i < numUsers; i++) {
        std::cout << "\t\"@" << profiles[i].getUsername() << "\"" << std::endl;
    }
    std::cout << "\n";

    for (int id1 = 0; id1 < numUsers; id1++) {
        for (int id2 = 0; id2 < numUsers; id2++) {
            if (following[id1][id2] == true) {
                    std::cout << "\t\"@" << profiles[id1].getUsername() << "\" -> \"@" << profiles[id2].getUsername() << "\"" << std::endl;
            }
        }
    }
    std::cout << "}" << std::endl;
    return;
}
