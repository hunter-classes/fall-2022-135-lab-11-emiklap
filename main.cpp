#include <iostream>
#include <string>
#include "profile.h"
#include "network.h"

int main() {
    std::cout << "------------PART A------------\n" << std::endl;
    Profile p1("marco", "Marco");
    std::cout << p1.getUsername() << std::endl; // marco
    std::cout << p1.getFullName() << std::endl; // Marco (@marco)

    p1.setDisplayName("Marco Rossi");
    std::cout << p1.getUsername() << std::endl; // marco
    std::cout << p1.getFullName() << std::endl; // Marco Rossi (@marco)

    Profile p2("tarma1", "Tarma Roving");
    std::cout << p2.getUsername() << std::endl; // tarma1
    std::cout << p2.getFullName() << std::endl; // Tarma Roving (@tarma1)

    std::cout << "\n------------PART B------------\n" << std::endl;
    Network nw;
    std::cout << "nw.addUser('mario', 'Mario'): " << nw.addUser("mario", "Mario") << std::endl;     // true (1)
    std::cout << "nw.addUser('luigi', 'Luigi'): " << nw.addUser("luigi", "Luigi") << std::endl;     // true (1)

    std::cout << "nw.addUser('mario', 'Mario2'): " << nw.addUser("mario", "Mario2") << std::endl;    // false (0)
    std::cout << "nw.addUser('mario 2', 'Mario2'): " << nw.addUser("mario 2", "Mario2") << std::endl;  // false (0)
    std::cout << "nw.addUser('mario-2', 'Mario2'): " << nw.addUser("mario-2", "Mario2") << std::endl;  // false (0)

    std::cout << "\n------------PART C------------\n" << std::endl;
    nw.addUser("yoshi", "Yoshi");
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");
    // add a user who does not follow others
    nw.addUser("wario", "Wario");
    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        std::string usrn = "mario" + std::__cxx11::to_string(i);
        std::string dspn = "Mario " + std::__cxx11::to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    nw.follow("mario2", "luigi");

    nw.printDot();

    return 0;
}
