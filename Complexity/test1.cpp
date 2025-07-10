// =================================================================
//
// File: test1.cpp
// Author: Pedro Perez
// Description: This file contains the test cases for the functions
//				of this activity have to pass. IMPORTANT: this file
//				should not be modified.
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.h"
#include "activity.h"

TEST_CASE( "Testing iterativeSum", "[iterativeSum]" ) {
	REQUIRE(iterativeSum(1) == 1);
	REQUIRE(iterativeSum(10) == 55);
	REQUIRE(iterativeSum(50) == 1275);
	REQUIRE(iterativeSum(100) == 5050);
	REQUIRE(iterativeSum(500) == 125250);
}

TEST_CASE( "Testing recursiveSum", "[recursiveSum]" ) {
	REQUIRE(recursiveSum(1) == 1);
	REQUIRE(recursiveSum(10) == 55);
	REQUIRE(recursiveSum(50) == 1275);
	REQUIRE(recursiveSum(100) == 5050);
	REQUIRE(recursiveSum(500) == 125250);
}

TEST_CASE( "Testing directSum", "[directSum]" ) {
	REQUIRE(directSum(1) == 1);
	REQUIRE(directSum(10) == 55);
	REQUIRE(directSum(50) == 1275);
	REQUIRE(directSum(100) == 5050);
	REQUIRE(directSum(500) == 125250);
}
