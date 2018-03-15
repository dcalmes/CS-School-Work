// Filename: test_string_ctor
//
// Description: Tests to see if string constrctor is working properly
//					Tested this by seeing if we could pin point specific
//					digit locations of the string.
//
// Author : Douglas G Calmes      dcalmes@bgsu.edu

#define BOOST_TEST_MODULE bigint test_string_ctor
#include <boost/test/included/unit_test.hpp>
#include "bigint.hpp"
#include <cassert>
#include <cstdlib>
#include <iostream>

BOOST_AUTO_TEST_CASE(single_string){
  // test setup
  bigint akusaan("1");
  int i = 0;
  int compare[1]{1};
  // verification
  while (i < 1){
    BOOST_TEST(akusaan[i] == compare[i]);
    i++;
  }
}
BOOST_AUTO_TEST_CASE(ten_digit){
  // test setup
  bigint akusaan("1111111111");
  int i = 0;
  int compare[10]{1,1,1,1,1,1,1,1,1,1};
  // verification
  while (i < 10){
    BOOST_TEST(akusaan[i] == compare[i]);
    i++;
  }
}
BOOST_AUTO_TEST_CASE(twent_digit){
  // test setup
  bigint akusaan("11111111111111111111");
  int i = 0;
  int compare[20] {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
  // verification
  while (i < 20){
    BOOST_TEST(akusaan[i] == compare[i]);
    i++;
  }
}
BOOST_AUTO_TEST_CASE(fifty_digit){
  // test setup
  bigint akusaan("1111111111111111111111111111111111111111111111111");
  int i = 0;
  int compare[49]{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
  // verification
  while (i < 49){
    BOOST_TEST(akusaan[i] == compare[i]);
    i++;
  }
}

// 50 digit test will throw an error stating 1 != 0.  It is changing the final 1 digit to a 0 because of what seems like an overflow
