#include "catch.hpp"
#include "../schmitt/trigger.hpp"

TEST_CASE("Two probes across the thresholds for the inverted trigger (once)", "[positive]") {
    auto const low = -1.f, high = 2.f;
    bool const default_out = true;
    auto st = schmitt::trigger_inverting<float>(low, high, default_out);
    CHECK(st(0.f));
    REQUIRE(!st(high + 1.f));
}

TEST_CASE("Cycling the inverted trigger (once)", "[positive]") {
    auto const low = 1.f, high = 2.f;
    bool const default_out = false;
    auto st = schmitt::trigger_inverting<float>(low, high, default_out);
    float m = 2., step = 1.f;
    auto cycles = 1;
    do {
        INFO("Rising ...");
        bool expected_state = false;
        for (; m < high + step ; m += step) {
            CHECK(st(m) == expected_state);
        }
        CHECK(st(m) == expected_state);
        INFO("Sinking ...");
        for (; m > low - step; m -= step) {
            CHECK(st(m) == expected_state);
        }
        expected_state = true;
        REQUIRE(st(m) == expected_state);
    } while (--cycles);
}
