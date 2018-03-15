// Filename: test_default_ctor
//
// Description: Tests to see if the add will carry properly, as well as,
//					testing adding bigints at upper and lower bounds.
//
// Author : Douglas G Calmes      dcalmes@bgsu.edu
#define BOOST_TEST_MODULE bigint add_test
#include <boost/test/included/unit_test.hpp>
#include "bigint.hpp"
#include <cstdlib>
#include <iostream>

BOOST_AUTO_TEST_CASE(carryTest){
  // test setup
  bigint aku("5");
  bigint saan("5");
  bigint akusaan;
  // test
  akusaan = operator+(aku, saan);
  int carrytest = akusaan[1];
  // verification
  BOOST_TEST(carrytest == 1);
}

BOOST_AUTO_TEST_CASE(onePLUStwo){
  // test setup
  bigint aku("1");
  bigint saan("2");
  bigint akusaan;
  int addtest[1] = {3};
  int i = 0;
  // test
  akusaan = operator+(aku, saan);
  // verification
  while (i < 1){
    BOOST_TEST(addtest[i]==akusaan[i]);
    i++;
  }
}

BOOST_AUTO_TEST_CASE(twoPLUSone){
  // test setup
  bigint aku("2");
  bigint saan("1");
  bigint akusaan;
  int addtest[1] = {3};
  int i = 0;
  // test
  akusaan = operator+(aku, saan);
  // verification
  while (i < 1){
    BOOST_TEST(addtest[i] == akusaan[i]);
    i++;
  }
}

BOOST_AUTO_TEST_CASE(tenDIGITaddition){
  // test setup
  bigint aku("1111111111");
  bigint saan("2222222222");
  bigint akusaan;
  int addtest[10] = {3,3,3,3,3,3,3,3,3,3};
  int i = 0;
  // test
  akusaan = operator+(aku, saan);
  // verification
  while (i < 10){
    BOOST_TEST(addtest[i] == akusaan[i]);
    i++;
  }
}

BOOST_AUTO_TEST_CASE(tenDIGITaddition2){
  // test setup
  bigint aku("1111111111");
  bigint saan("2222222222");
  bigint akusaan;
  int addtest[10] = {3,3,3,3,3,3,3,3,3,3};
  int i = 0;
  // test
  akusaan = operator+(saan, aku);
  // verification
  while (i < 10){
    BOOST_TEST(addtest[i] == akusaan[i]);
    i++;
  }
}

BOOST_AUTO_TEST_CASE(tenPLUSone){
  // test setup
  bigint aku("1");
  bigint saan("2222222222");
  bigint akusaan;
   int addtest[10] = {3,2,2,2,2,2,2,2,2,2};
  int i = 0;
  // test
  akusaan = operator+(saan, aku);
  // verification
   while (i < 10){
   BOOST_TEST(addtest[i] == akusaan[i]);
   i++;
   }
}

BOOST_AUTO_TEST_CASE(onePLUSten){
  // test setup
  bigint aku("1");
  bigint saan("2222222222");
  bigint akusaan;
  int addtest[10] = {3,2,2,2,2,2,2,2,2,2};
  int i = 0;
  // test
  akusaan = operator+(aku, saan);
  // verification
  while (i < 10){
    BOOST_TEST(addtest[i] == akusaan[i]);
    i++;
  }
}

BOOST_AUTO_TEST_CASE(largeaddition){
  // test setup
  bigint aku("1111111111111111111111111111111111111111111111111");
  bigint saan("2222222222222222222222222222222222222222222222222");
  bigint akusaan;
  int addtest[49] = {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3};
  int i = 0;
  // test
  akusaan = operator+(aku, saan);
  // verification
  while (i < 49){
    BOOST_TEST(addtest[i] == akusaan[i]);
    i++;
  }
}

BOOST_AUTO_TEST_CASE(largeaddition2){
  // test setup
  bigint aku("1111111111111111111111111111111111111111111111111");
  bigint saan("2222222222222222222222222222222222222222222222222");
  bigint akusaan;
  int addtest[49] = {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3};
  int i = 0;
  // test
  akusaan = operator+(saan, aku);
  // verification
  while (i < 49){
    BOOST_TEST(addtest[i] == akusaan[i]);
    i++;
  }
}

BOOST_AUTO_TEST_CASE(largeadditionsmall){
  // test setup
  bigint aku("1");
  bigint saan("2222222222222222222222222222222222222222222222222");
  bigint akusaan;
  int addtest[49] = {3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
  int i = 0;
  // test
  akusaan = operator+(saan, aku);
  // verification
  while (i < 49){
    BOOST_TEST(addtest[i] == akusaan[i]);
    i++;
  }
}

BOOST_AUTO_TEST_CASE(largeadditionmedium){
  // test setup
  bigint aku("1111111111");
  bigint saan("2222222222222222222222222222222222222222222222222");
  bigint akusaan;
  int addtest[49] = {3,3,3,3,3,3,3,3,3,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
  int i = 0;
  // test
  akusaan = operator+(saan, aku);
  // verification
  while (i < 49){
    BOOST_TEST(addtest[i] == akusaan[i]);
    i++;
  }
}

/*int main(){
{
	//setup
	bigint aku(5);
	bigint apple(5);
	bigint sum;
	//test
	sum = operator+(apple, aku);
	int test = sum[1];
	//verify
	assert(test == 1);
}
{
	//setup
	bigint aku(1111111111);
	bigint apple(1111111111);
	bigint sum;
	int array[10] = {2,2,2,2,2,2,2,2,2,2};
	int i = 0;
	//test
	sum = operator+(apple, aku);
	//verify
	while (i < 9){
	assert(sum[i] == array[i]);
}
}
{
	//setup
	bigint aku(5);
	bigint apple(5);
	bigint sum;
	int array[50] = {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
	int i = 0;
	//test
	sum = operator+(apple, aku);
	//verify
	while (i < 49){
	assert(sum[i] == array[i]);
}
}

return 0;
}
*/
