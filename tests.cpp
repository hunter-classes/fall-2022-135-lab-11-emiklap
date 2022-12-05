#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "profile.h"
#include "network.h"
#include <string>

// add your tests here
TEST_CASE("Task A: Profile") {
    Profile p1("therealmario", "Mario");
    Profile p2("silentlink", "Link");

    CHECK(p1.getUsername() == "therealmario");
    CHECK(p1.getFullName() == "Mario (@therealmario)");
    p1.setDisplayName("Mario Brother");
    CHECK(p1.getUsername() == "therealmario");
    CHECK(p1.getFullName() == "Mario Brother (@therealmario)");
    CHECK(p2.getUsername() == "silentlink");
    CHECK(p2.getFullName() == "Link (@silentlink)");
    p2.setDisplayName("Dark Link");
    CHECK(p2.getFullName() == "Dark Link (@silentlink)");
}

TEST_CASE("Task B: Network") {
    Network nw;
    CHECK(nw.addUser("mario", "Mario") == 1);
    CHECK(nw.addUser("luigi", "Luigi") == 1);
    CHECK(nw.addUser("mario", "Mario2") == 0);
    CHECK(nw.addUser("mario 2", "Mario2") == 0);
    CHECK(nw.addUser("mario-2", "Mario2") == 0);
    CHECK(nw.addUser("mario!2", "Mario2") == 0);

    //fill up the network
    for(int i = 2; i < 20; i++) {
        nw.addUser("mario" + std::__cxx11::to_string(i), "Mario" + std::__cxx11::to_string(i));
    }
    CHECK(nw.addUser("mario200000", "Mario") == 0);
}
