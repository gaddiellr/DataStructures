#define CATCH_CONFIG_MAIN
#include <iostream>
#include <fstream>
#include <string>
#include "catch.h"
#include "priority_queue.h"
using namespace std;

TEST_CASE( "Testing priority queue implementation", "[PriorityQueue]" ) {
	PriorityQueue<int> p(3);

	SECTION( "1: Testing if the priority queue is empty." ) {
		REQUIRE(p.empty() == true);
	}

	SECTION( "2: Checking size of priority queue" ) {
		p.push(10); p.push(1);
		REQUIRE(p.size() == 2);
	}

	SECTION( "3: Putting an element in the priority queue" ) {
		p.push(10);
		REQUIRE(strcmp(p.toString().c_str(), "[10]") == 0);
		p.push(1);
		REQUIRE(strcmp(p.toString().c_str(), "[1 10]") == 0);
		p.push(5);
		REQUIRE(strcmp(p.toString().c_str(), "[1 10 5]") == 0);
		REQUIRE_THROWS_AS(p.push(11), Overflow);
	}

	SECTION( "4: Removing an element in the priority queue" ) {
		p.push(10); p.push(1); p.push(5);
		p.pop();
		REQUIRE(strcmp(p.toString().c_str(), "[5 10]") == 0);
		p.pop();
		REQUIRE(strcmp(p.toString().c_str(), "[10]") == 0);
		p.pop();
		REQUIRE(strcmp(p.toString().c_str(), "[]") == 0);
		REQUIRE_THROWS_AS(p.pop(), NoSuchElement);
	}

	SECTION( "5: Top priority element in the priority queue" ) {
		int x;
		p.push(10); p.push(1); p.push(5);
		x = p.top();
		REQUIRE(x == 1);
	}
}

