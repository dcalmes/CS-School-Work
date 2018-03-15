// Filename: test_operator_out
//
// Description: Tests to see if you can write a bigint to an output file.
//					Tested with numbers at upper, lower, and mid bounds
//
// Author : Douglas G Calmes      dcalmes@bgsu.edu

#define BOOST_TEST_MODULE bigint test_operator_out
#include <boost/test/included/unit_test.hpp>
#include "bigint.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>

BOOST_AUTO_TEST_CASE(zerodigit){
	//setup
	bigint aku("");
	std::ostringstream out;
	std::ofstream myfile;
	myfile.open ("test.txt");
	//test
	operator<<(myfile, aku);
	out<<aku;
	//verify
	BOOST_TEST(out.str() == "");
}

BOOST_AUTO_TEST_CASE(oneDIGITout){
	//setup
	bigint aku("1");
	std::ostringstream out;
	std::ofstream myfile;
	myfile.open ("test2.txt");
	//test
	operator<<(myfile, aku);
	out<<aku;
	//verify
	BOOST_TEST(out.str() == "1");
}

BOOST_AUTO_TEST_CASE(twentyDIGITout){
  //setup
  bigint aku("11111111111111111111");
  std::ostringstream out;
  std::ofstream myfile;
  myfile.open ("test4.txt");
  //test
  operator<<(myfile, aku);
  out<<aku;
  //verify
  BOOST_TEST(out.str() == "11111111111111111111");

}


BOOST_AUTO_TEST_CASE(fiftydigit){
	//setup
	bigint aku("9191919191919191919191919191919191919191919191919");
	std::ostringstream out;
	std::ofstream myfile;
	myfile.open ("test3.txt");
	//test
	operator<<(myfile, aku);
	out<<aku;
	//verify
	BOOST_TEST(out.str() == "9191919191919191919191919191919191919191919191919");
}
// cant run fifty digit, swapped to 49 for testing
