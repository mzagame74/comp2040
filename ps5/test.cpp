// Copyright 2020 Matt Zagame
#include "MModel.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(base_test) {
    std::cout << "******************** Test Case 1 ********************" <<
    std::endl;

    int k = 2;
    std::string str = "gagggagaggcgagaaa";
    MModel mmodel(str, k);

    std::cout << "Printing out Markov Table for string:\n" <<
    str << std::endl << std::endl;
    std::cout << mmodel << std::endl;

    std::cout << "Testing kOrder and freq functions" << std::endl;
    BOOST_REQUIRE(mmodel.kOrder() == k);
    BOOST_REQUIRE(mmodel.freq("gg") == 3);
    BOOST_REQUIRE(mmodel.freq("ga", 'g') == 4);

    std::cout << "Testing kRand function" << std::endl;
    char rand = mmodel.kRand("aa");
    BOOST_REQUIRE(rand == 'a' || rand == 'g');

    std::cout << "Testing generate function" << std::endl << std::endl;
    BOOST_REQUIRE(mmodel.generate("ga", 10).length() == 10);
}

BOOST_AUTO_TEST_CASE(exception_test) {
    std::cout << "******************** Test Case 2 ********************" <<
    std::endl;
    std::cout << "Testing construction exception: MModel('ADF', 4)" <<
    std::endl;

    BOOST_REQUIRE_THROW(MModel("ADF", 4), std::invalid_argument);

    std::cout << "Testing function exceptions" << std::endl;
    MModel testMM("abc", 3);
    BOOST_REQUIRE_THROW(testMM.freq("a"), std::runtime_error);
    BOOST_REQUIRE_THROW(testMM.freq("ab", 'b'), std::runtime_error);
    BOOST_REQUIRE_THROW(testMM.kRand("g"), std::runtime_error);
}
