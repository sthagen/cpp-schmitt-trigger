#include "catch.hpp"
#include "../schmitt/trigger.hpp"

TEST_CASE("Cycling (once)", "[positive]") {
    auto const low = -1.f, high = 2.f;
    bool const default_out = false;
    auto st = schmitt::trigger_inverting<float>(low, high, default_out);
    CHECK(st(0.f));
    REQUIRE(!st(high + 1.f));
}
