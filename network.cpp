#include <iostream>
#include <string>
#include <algorithm>
#include "profile.h"
#include "network.h"

Network::Network() {
    numUsers = 0;
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
