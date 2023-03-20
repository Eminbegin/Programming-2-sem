#ifndef GOOTESTS_HPP
#define GOOTESTS_HPP

#include <gtest/gtest.h>
#include "poly.hpp"

TEST(Test, Answer) {
    Poly<0, 0, 0, 0> pol1;
    ASSERT_EQ(0 + 0 + 0 + 0, pol1.findValue(1));

    Poly<40, -4, 2, 84> pol2;
    ASSERT_EQ(40 - 40 + 200 + 84000, pol2.findValue(10));

    Poly<12, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2> pol3;
    ASSERT_EQ(12, pol3.findValue(0));

    Poly<> pol4;
    ASSERT_EQ(0, pol4.findValue(12312));

    Poly<1, 1, 1> pol5;
    ASSERT_EQ(534696253, pol5.findValue(23123));

    Poly< -1, 0, 0, 0, -1, -1, -1> pol6;
    ASSERT_EQ(-2, pol6.findValue(-1));

    Poly<34523, 2234, 8977, 21, 111, 12312, 43215, 542> pol_1;
    std::stringstream out1;
    out1 << pol_1;
    ASSERT_EQ("34523 + 2234x + 8977x^2 + 21x^3 + 111x^4 + 12312x^5 + 43215x^6 + 542x^7", out1.str());

    Poly< -40, 53, 0, 0, 12, 0, -2, 1> pol_2;
    std::stringstream out2;
    out2 << pol_2;
    ASSERT_EQ("-40 + 53x + 12x^4 - 2x^6 + x^7", out2.str());

    Poly<> pol_3;
    std::stringstream out3;
    out3 << pol_3;
    ASSERT_EQ("0", out3.str());

    Poly<0, 0, 0, 0, 0, 0 ,0> pol_4;
    std::stringstream out4;
    out4 << pol_4;
    ASSERT_EQ("0", out4.str());

    Poly<-1, -1, 99, -1, 0, 0, 99, 0> pol_5;
    std::stringstream out5;
    out5 << pol_5;
    ASSERT_EQ("-1 - x + 99x^2 - x^3 + 99x^6", out5.str());
}

#endif
