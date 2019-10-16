#include "cuslib/chef.cpp"
#include "cuslib/clib.cpp"
#include "stdio.h"

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

enum funclist {b2b}; //Enumeration of callable functions.

//static logStatistics logstats;
std::string numsstr[] = {"one","two","three","four","five","six","seven"};

// The help string for -h
std::string help_notice = "Use stuff.\n \
-v   : Activates Verbose mode, displays information realtime in terminal.\n \
-l   : Sends more information into the log regarding runtime.\n \
-t   : Given an integer, gets sql test from database and runs it.\n TODO \
-tall: Runs all associated sql tests in related database.\n TODO \
-tadd: Adds a given test case to the database.\n\
Functions:\n \
one  []		  - Test case for no reason\n \
b2b  [int]    - calculates bits in bytes\n \
pali [string] - calculates whether or not a string is a palindrome.\
";
