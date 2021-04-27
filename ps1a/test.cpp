// Copyright 2020 Matt Zagame
#include <iostream>
#include <string>
#include "FibLFSR.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(sixteenBitsThreeTaps) {

  FibLFSR l("1011011000110110");
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);

  FibLFSR l2("1011011000110110");
  BOOST_REQUIRE(l2.generate(9) == 51);
}

/** A simple test case to print out the starting and resulting bit
 * patterns and check to make sure the right result is printed **/
BOOST_AUTO_TEST_CASE(my_test1) {
  std::cout << "\n************ My Test Case 1 ************" << std::endl;
  FibLFSR lfsr("1011011000110110");
  std::cout << "    Original seed: " << lfsr << std::endl;

  int result = lfsr.generate(5);
  BOOST_REQUIRE(result == 3);

  std::cout << "After generate(5): " << lfsr << " " << result << std::endl;
  std::cout << std::endl;
}

/** A test case to make sure the invalid_argument exception is thrown 
 * when given a seed either too long or too short */
BOOST_AUTO_TEST_CASE(my_test2) {
  std::cout << "\n************ My Test Case 2 ************" << std::endl;
  std::string testSeed1 = "0101100101";
  std::string testSeed2 = "0111011000110110101100101";

  std::cout << "Testing exception thrown when seed is too short: 0101100101"
  << std::endl;
  BOOST_REQUIRE_THROW(FibLFSR("0101100101"), std::invalid_argument);

  std::cout << "Testing exception thrown when seed is too long : "
  "0111011000110110101100" << std::endl;
  BOOST_REQUIRE_THROW(FibLFSR("0111011000110110101100"),
  std::invalid_argument);  
}
