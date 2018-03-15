// Filename: test_default_ctor
//
// Description: Tests to see if default constructor is set to 0
//
// Author : Douglas G Calmes      dcalmes@bgsu.edu

#define BOOST_TEST_MODULE bigint defaultCtor
#include <boost/test/included/unit_test.hpp>
#include <iostream>
#include <cstdlib>
#include "bigint.hpp"


BOOST_AUTO_TEST_CASE(default_ctor){
  // test setup
  bigint empty;
  // verification
  /* while (i < 1){
  BOOST_TEST(empty[i] == compare[i]);
  i++;
  }*/
  BOOST_TEST(empty[0] == 0);
}
