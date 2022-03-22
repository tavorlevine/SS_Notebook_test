#include "doctest.h"
#include "Notebook.hpp"
#include "Direction.hpp"
using namespace ariel;
//using ariel::Direction;

#include <string>
#include <algorithm>
using namespace std;


/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


 

TEST_CASE("Check read,write and erase function - good input") {
    ariel::Notebook Notebook1;
    Notebook1.write(3,5,0,Direction::Horizontal,"aaa");
    Notebook1.write(5,2,7,Direction::Horizontal, "Hello-World");
    Notebook1.write(10,6,1,Direction::Vertical, "Tavor-Levine");
	CHECK(nospaces(Notebook1.read(3,5,1,Direction::Horizontal,3)) == nospaces("aa_"));
    CHECK(nospaces(Notebook1.read(5,2,12,Direction::Horizontal,1)) == nospaces("-"));
    CHECK(nospaces(Notebook1.read(5,2,9,Direction::Horizontal,6)) == nospaces("llo-Wo"));
    CHECK(nospaces(Notebook1.read(10,6,1,Direction::Vertical,3)) == nospaces("Tav"));
    CHECK(nospaces(Notebook1.read(3,5,1,Direction::Vertical,3)) == nospaces("a__"));
    CHECK(nospaces(Notebook1.read(10,6,11,Direction::Vertical,7)) == nospaces("n______"));
    CHECK(nospaces(Notebook1.read(5,0,15,Direction::Vertical,10)) == nospaces("__r_______"));
    Notebook1.erase(40,23,8,Direction::Vertical, 10);
    Notebook1.erase(10,11,1,Direction::Vertical, 8);
    Notebook1.erase(5,2,12,Direction::Horizontal, 1);
    CHECK(nospaces(Notebook1.read(40,23,9,Direction::Vertical,10)) == nospaces("~~~~~~~~~_"));
    CHECK(nospaces(Notebook1.read(40,23,8,Direction::Horizontal,3)) == nospaces("~__"));
    CHECK(nospaces(Notebook1.read(10,5,1,Direction::Vertical,8)) == nospaces("_Tavor~~"));
    CHECK(nospaces(Notebook1.read(5,2,12,Direction::Horizontal,5)) == nospaces("~Worl"));
    CHECK(nospaces(Notebook1.read(5,0,12,Direction::Vertical,4)) == nospaces("__~_"));
}

TEST_CASE("Check write function - bad input") {
    ariel::Notebook Notebook1;
    CHECK_THROWS(Notebook1.write(1,-3,6,Direction::Vertical,"Hello"));
    CHECK_THROWS(Notebook1.write(-61,40,7,Direction::Vertical,"Hello"));
    CHECK_THROWS(Notebook1.write(1,10,96,Direction::Horizontal,"Hello"));
    CHECK_THROWS(Notebook1.write(1,367,99,Direction::Horizontal,"Hello"));
    CHECK_THROWS(Notebook1.write(1,72,100,Direction::Vertical,"Hello"));
    CHECK_THROWS(Notebook1.write(1,-3,110,Direction::Vertical,"Hello"));  
}

TEST_CASE("Check read function - bad input") {
    ariel::Notebook Notebook1;
    CHECK_THROWS(Notebook1.read(1,-3,6,Direction::Vertical,5));
    CHECK_THROWS(Notebook1.read(-41,-32,4,Direction::Vertical,8));
    CHECK_THROWS(Notebook1.read(-11,5,6,Direction::Vertical,5));
    CHECK_THROWS(Notebook1.read(1,3,6,Direction::Horizontal,99));
    CHECK_THROWS(Notebook1.read(1,43,16,Direction::Horizontal,90));
    CHECK_THROWS(Notebook1.read(8,12,0,Direction::Horizontal,101));
 
}

TEST_CASE("Check erase function - bad input") {
    ariel::Notebook Notebook1;
    CHECK_THROWS(Notebook1.erase(-21,0,6,Direction::Vertical,2));
    CHECK_THROWS(Notebook1.erase(1,-93,3,Direction::Vertical,12));
    CHECK_THROWS(Notebook1.erase(13,66,42,Direction::Horizontal,90));
    CHECK_THROWS(Notebook1.erase(278,9234,6,Direction::Horizontal,99));
    CHECK_THROWS(Notebook1.erase(1,85,3,Direction::Horizontal,110));
}

