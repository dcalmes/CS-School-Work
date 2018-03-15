// Filename: test_int_ctor
//
// Description: Tests to see if int constructor is working properly
//					Used numbers at the upper, lower, and mid bounds
//
// Author : Douglas G Calmes      dcalmes@bgsu.edu

#define BOOST_TEST_MODULE bigint test_int_ctor
#include <boost/test/included/unit_test.hpp>
#include "bigint.hpp"
#include <cassert>
#include <cstdlib>
#include <iostream>

BOOST_AUTO_TEST_CASE(zero){
  // setup
  bigint grey(0);
  int i = 0;
  int compare[1]{0};
  // test
  // verify
  while (i < 1){
    BOOST_TEST(grey[i] == compare[i]);
    i++;
  }
}

BOOST_AUTO_TEST_CASE(four){
  //setup
  bigint aku(9000);
  int i = 0;
  int compare[4]{0,0,0,9};
  //test
  //verify
  while (i < 4){
    BOOST_TEST(aku[i] == compare[i]);
    i++;
  }
}
	
BOOST_AUTO_TEST_CASE(nine){
  //setup
  bigint vicktor(214748364);
  int i = 0;
  int compare[9]{4,6,3,8,4,7,4,1,2};
  //test
  //verify
  while (i < 9){
    BOOST_TEST(vicktor[i] == compare[i]);
    i++;
  }
}
