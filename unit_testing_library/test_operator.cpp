// Filename: test_operator
//
// Description: Tests to see if you can check a specific digit location.  Tested it at upper, lower, and mid bound
//
// Author : Douglas G Calmes      dcalmes@bgsu.edu
#define BOOST_TEST_MODULE bigint test_operator
#include <boost/test/included/unit_test.hpp>
#include "bigint.hpp"
#include <cassert>
#include <cstdlib>
#include <iostream>


BOOST_AUTO_TEST_CASE(testone){
    // setup
    bigint b("1000000000000000000000000200000000000000000000000");
    b = b.times_10(1);
    b = b + 3;

    // test
    int result = b[0];
    int result2 = b[24];
    // verify
    BOOST_TEST(result == 3);
    BOOST_TEST(result2 == 2);
  }
/*
BOOST_AUTO_TEST_CASE(testtwo) {
    // setup
    bigint b("1000000000000000000000000200000000000000000000000");
    b = b.times_10(1);
    b = b + 3;

    // test
    int result = b[24];

    // verify
    BOOST_TEST(result == 2);
  }*/

BOOST_AUTO_TEST_CASE(testthree) {
    // setup
    bigint b("1000000000000000000000000200000000000000000000000");
    b = b.times_10(1);
    b = b + 3;

    // test
    int result = b[49];

    // verify
    BOOST_TEST(result == 1);
  }
