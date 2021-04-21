#include <fstream>
#include <iostream>
#include "doctest.h"
#include <stdexcept>
#include "NumberWithUnits.hpp"

using namespace std;
using namespace ariel;

ifstream unit_file{"units.txt"};

TEST_CASE("Test read_units - valid input")
{
    NumberWithUnits::read_units(unit_file);
    NumberWithUnits a(1, "km");
    NumberWithUnits b(1, "m");
    NumberWithUnits c(1, "cm");
    NumberWithUnits d(1, "kg");
    NumberWithUnits e(1, "g");
    NumberWithUnits f(1, "ton");
    NumberWithUnits g(1, "hour");
    NumberWithUnits h(1, "min");
    NumberWithUnits i(1, "sec");
    NumberWithUnits j(1, "USD");
    NumberWithUnits k(1, "ILS");

}

TEST_CASE("Test read_units - invalid input")
{
    NumberWithUnits::read_units(unit_file);
    CHECK_THROWS(NumberWithUnits a(1, "Km"));
    CHECK_THROWS(NumberWithUnits b(1, "M"));
    CHECK_THROWS(NumberWithUnits c(1, "cM"));
    CHECK_THROWS(NumberWithUnits d(1, "KG"));
    CHECK_THROWS(NumberWithUnits e(1, "G"));
    CHECK_THROWS(NumberWithUnits f(1, "tOn"));
    CHECK_THROWS(NumberWithUnits g(1, "hoUR"));
    CHECK_THROWS(NumberWithUnits h(1, "MIn"));
    CHECK_THROWS(NumberWithUnits i(1, "sEC"));
    CHECK_THROWS(NumberWithUnits j(1, "usd"));
    CHECK_THROWS(NumberWithUnits k(1, "ils"));

}

TEST_CASE("Test operator +")
{
    NumberWithUnits a(10, "km");
    NumberWithUnits b(200, "m");
    NumberWithUnits c(30, "cm");
    NumberWithUnits d(40, "kg");
    NumberWithUnits e(500, "g");
    NumberWithUnits f(60, "ton");
    NumberWithUnits g(5, "hour");
    NumberWithUnits h(35, "min");
    NumberWithUnits i(45, "sec");
    NumberWithUnits j(150, "USD");
    NumberWithUnits k(1000, "ILS");

    CHECK(a + b == NumberWithUnits(10.2, "km"));
    CHECK(b + a == NumberWithUnits(10200,"m"));
    CHECK(a + a == NumberWithUnits(20, "km"));
    CHECK(b + b == NumberWithUnits(400, "m"));
    CHECK(b + c == NumberWithUnits(200.3, "cm"));
    CHECK(c + b == NumberWithUnits(20030, "cm"));
    CHECK(d + e == NumberWithUnits(40.5, "kg"));
    CHECK(e + d == NumberWithUnits(40500, "g"));
    CHECK(d + f == NumberWithUnits(60040, "kg"));
    CHECK(f + d == NumberWithUnits(60.04, "ton"));
    CHECK(f + e == NumberWithUnits(60.0005, "ton"));
    CHECK(e + f == NumberWithUnits(60000500, "g"));

    //different dimensions
    CHECK_THROWS(a + d);
    CHECK_THROWS(d + a);
    CHECK_THROWS(f + g);
    CHECK_THROWS(i + j);
    CHECK_THROWS(h + k);
    CHECK_THROWS(c + d);

    NumberWithUnits a_neg(-10, "km");
    NumberWithUnits b_neg(-200, "m");
    NumberWithUnits c_neg(-30, "cm");
    NumberWithUnits d_neg(-40, "kg");
    NumberWithUnits e_neg(-500, "g");
    NumberWithUnits f_neg(-60, "ton");
    NumberWithUnits g_neg(-5, "hour");
    NumberWithUnits h_neg(-35, "min");
    NumberWithUnits i_neg(-45, "sec");
    NumberWithUnits j_neg(-150, "USD");
    NumberWithUnits k_neg(-1000, "ILS");

    CHECK(+a == a);
    CHECK(+b == b);
    CHECK(+c == c);
    CHECK(+d == d);
    CHECK(+e == e);
    CHECK(+f == f);
    CHECK(+g == g);
    CHECK(+h == h);
    CHECK(+i == i);
    CHECK(+j == j);
    CHECK(+k == k);

    CHECK(+a_neg == a_neg);
    CHECK(+b_neg == b_neg);
    CHECK(+c_neg == c_neg);
    CHECK(+d_neg == d_neg);
    CHECK(+e_neg == e_neg);
    CHECK(+f_neg == f_neg);
    CHECK(+g_neg == g_neg);
    CHECK(+h_neg == h_neg);
    CHECK(+i_neg == i_neg);
    CHECK(+j_neg == j_neg);
    CHECK(+k_neg == k_neg);
}

TEST_CASE("Test operator -")
{
    NumberWithUnits a(10, "km");
    NumberWithUnits b(200, "m");
    NumberWithUnits c(30, "cm");
    NumberWithUnits d(40, "kg");
    NumberWithUnits e(500, "g");
    NumberWithUnits f(60, "ton");
    NumberWithUnits g(5, "hour");
    NumberWithUnits h(35, "min");
    NumberWithUnits i(45, "sec");
    NumberWithUnits j(150, "USD");
    NumberWithUnits k(1000, "ILS");

    CHECK(a - b == NumberWithUnits(9.8, "km"));
    CHECK(b - a == NumberWithUnits(-9800,"m"));
    CHECK(a - a == NumberWithUnits(0, "km"));
    CHECK(b - b == NumberWithUnits(0, "m"));
    CHECK(b - c == NumberWithUnits(199.7, "cm"));
    CHECK(c - b == NumberWithUnits(19970, "cm"));
    CHECK(d - e == NumberWithUnits(39.5, "kg"));
    CHECK(e - d == NumberWithUnits(39500, "g"));
    CHECK(d - f == NumberWithUnits(59960, "kg"));
    CHECK(f - d == NumberWithUnits(59.6, "ton"));
    CHECK(f - e == NumberWithUnits(59.9995, "ton"));
    CHECK(e - f == NumberWithUnits(59999500, "g"));

    //different dimensions
    CHECK_THROWS(a - d);
    CHECK_THROWS(d - a);
    CHECK_THROWS(f - g);
    CHECK_THROWS(i - j);
    CHECK_THROWS(h - k);
    CHECK_THROWS(c - d);

    NumberWithUnits a_neg(-10, "km");
    NumberWithUnits b_neg(-200, "m");
    NumberWithUnits c_neg(-30, "cm");
    NumberWithUnits d_neg(-40, "kg");
    NumberWithUnits e_neg(-500, "g");
    NumberWithUnits f_neg(-60, "ton");
    NumberWithUnits g_neg(-5, "hour");
    NumberWithUnits h_neg(-35, "min");
    NumberWithUnits i_neg(-45, "sec");
    NumberWithUnits j_neg(-150, "USD");
    NumberWithUnits k_neg(-1000, "ILS");

    CHECK(-a == a_neg);
    CHECK(-b == b_neg);
    CHECK(-c == c_neg);
    CHECK(-d == d_neg);
    CHECK(-e == e_neg);
    CHECK(-f == f_neg);
    CHECK(-g == g_neg);
    CHECK(-h == h_neg);
    CHECK(-i == i_neg);
    CHECK(-j == j_neg);
    CHECK(-k == k_neg);

    CHECK(-a_neg == a);
    CHECK(-b_neg == b);
    CHECK(-c_neg == c);
    CHECK(-d_neg == d);
    CHECK(-e_neg == e);
    CHECK(-f_neg == f);
    CHECK(-g_neg == g);
    CHECK(-h_neg == h);
    CHECK(-i_neg == i);
    CHECK(-j_neg == j);
    CHECK(-k_neg == k);
}

TEST_CASE("Test == and != operators")
{
    NumberWithUnits km(1, "km");
    NumberWithUnits m(1, "m");
    NumberWithUnits cm(1, "cm");
    NumberWithUnits kg(1, "kg");
    NumberWithUnits gr(1, "g");
    NumberWithUnits ton(1, "ton");
    NumberWithUnits hour(1, "hour");
    NumberWithUnits min(1, "min");
    NumberWithUnits sec(1, "sec");
    NumberWithUnits usd(1, "USD");
    NumberWithUnits ils(3.33, "ILS");

    CHECK(km == NumberWithUnits(1, "km"));
    CHECK(m == NumberWithUnits(1, "m"));
    CHECK(cm == NumberWithUnits(1, "cm"));
    CHECK(kg == NumberWithUnits(1, "kg"));
    CHECK(gr == NumberWithUnits(1, "g"));
    CHECK(ton == NumberWithUnits(1, "ton"));
    CHECK(hour == NumberWithUnits(1, "hour"));
    CHECK(min == NumberWithUnits(1, "min"));
    CHECK(sec == NumberWithUnits(1, "sec"));
    CHECK(usd == NumberWithUnits(1, "USD"));
    CHECK(ils == NumberWithUnits(3.33, "ILS"));

    CHECK(km == NumberWithUnits(1000, "m"));
    CHECK(m == NumberWithUnits(100, "cm"));
    CHECK(kg == NumberWithUnits(1000, "g"));
    CHECK(ton == NumberWithUnits(1000, "kg"));
    CHECK(hour == NumberWithUnits(60, "min"));
    CHECK(min == NumberWithUnits(60, "sec"));
    CHECK(usd == NumberWithUnits(3.33, "ILS"));

    //different dimensions
    bool flag;
    CHECK_THROWS(flag = km == gr);
    CHECK_THROWS(flag = m == ton);
    CHECK_THROWS(flag = hour == usd);
    CHECK_THROWS(flag = min == kg);
    CHECK_THROWS(flag = cm == min);
    CHECK_THROWS(flag = sec == km);

    //different dimensions
    CHECK_THROWS(flag = km != gr);
    CHECK_THROWS(flag = m != ton);
    CHECK_THROWS(flag = hour != usd);
    CHECK_THROWS(flag = min != kg);
    CHECK_THROWS(flag = cm != min);
    CHECK_THROWS(flag = sec != km);

    NumberWithUnits a(10, "km");
    NumberWithUnits b(200, "m");
    NumberWithUnits c(30, "cm");
    NumberWithUnits d(40, "kg");
    NumberWithUnits e(500, "g");
    NumberWithUnits f(60, "ton");
    NumberWithUnits g(5, "hour");
    NumberWithUnits h(35, "min");
    NumberWithUnits i(45, "sec");
    NumberWithUnits j(150, "USD");
    NumberWithUnits k(1000, "ILS");

    CHECK(a != b);
    CHECK(b != c);
    CHECK(d != e);
    CHECK(e != f);
    CHECK(d != f);
    CHECK(g != h);
    CHECK(i != h);
    CHECK(j != k);
}

TEST_CASE("Test > >= < <= operators")
{
    NumberWithUnits a(10, "km");
    NumberWithUnits b(200, "m");
    NumberWithUnits c(30, "cm");
    NumberWithUnits d(40, "kg");
    NumberWithUnits e(500, "g");
    NumberWithUnits f(60, "ton");
    NumberWithUnits g(5, "hour");
    NumberWithUnits h(35, "min");
    NumberWithUnits i(45, "sec");
    NumberWithUnits j(150, "USD");
    NumberWithUnits k(1000, "ILS");

    CHECK(a > b);
    CHECK(a >= b);
    CHECK(b > c);
    CHECK(f > e);
    CHECK(g >= h);
    CHECK(i < h);
    CHECK(j <= k);
    CHECK(g >= i);
    CHECK(a > c);
    CHECK(c <= b);
    CHECK(d < f);

    //different dimensions
    bool flag;
    CHECK_THROWS(flag = a < k);
    CHECK_THROWS(flag = a <= j);
    CHECK_THROWS(flag = b > e);
    CHECK_THROWS(flag = c >= k);
    CHECK_THROWS(flag = e < g);

}