#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "profile.h"

// add your tests here
TEST_CASE("Task A: Profile") {
    Profile p1("therealmario", "Mario");
    Profile p2("silentlink", "Link");

    CHECK(p1.getUsername() == "therealmario");
    CHECK(p1.getFullName() == "Mario (@therealmario)");
    p1.setDisplayName("Mario Brother");
    CHECK(p1.getFullName() == "Mario Brother (@therealmario)");
    CHECK(p2.getUsername() == "silentlink");
    CHECK(p2.getFullName() == "Link (@silentlink)");
    p2.setDisplayName("Dark Link");
    CHECK(p2.getFullName() == "Dark Link (@silentlink)");
}
