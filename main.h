#include "cuslib/chef.cpp"
#include "cuslib/clib.cpp"
#include "stdio.h"

#include <iostream>
#include <string>
#include <algorithm>

enum funclist {b2b}; //Enumeration of callable functions.

//static logStatistics logstats;
std::string numsstr[] = {"one","two","three","four","five","six","seven"};


// The help string for -h
std::string help_notice = "Use stuff.\n\
b2b  [int]    - calculates bits in bytes\n\
pali [string] - calculates whether or not a string is a palindrome.\
";
