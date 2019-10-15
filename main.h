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
-v   : Activates Verbose mode, displays information realtime in terminal. \
-l   : Sends more information into the log regarding runtime. \
-t   : Given an integer, gets sql test from database and runs it. TODO \
-tall: Runs all associated sql tests in related database. TODO \
-tadd: Adds a given test case to the database. TODO \
one  []		  - Test case for no reason \
b2b  [int]    - calculates bits in bytes\n \
pali [string] - calculates whether or not a string is a palindrome.\
";
