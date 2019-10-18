#include "cuslib/chef.cpp"
#include "cuslib/clib.cpp"
#include "stdio.h"

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

class deFunct{// Class for holding directory data
	std::string name;
	std::string dir;
	public:
	deFunct(std::string tname, std::string tdir){
		name = tname;
		dir = tdir;
	}
	deFunct(){
		
	}
	std::string get(){
		return name;
	}
	std::string loc(){
		return dir;
	}
	
};

//void init();
//List of all functions
std::vector<deFunct> allFunc;
deFunct b2b("b2b", "Byte2Bit");
deFunct pali("pali", "Palindrome");

void init(){
	allFunc.push_back(b2b);
	allFunc.push_back(pali);
}

// The help string for -h
std::string help_notice = "Use stuff.											\n \
-v   : Activates Verbose mode, displays information realtime in terminal.		\n \
-l   : Sends more information into the log regarding runtime.					\n \
-t   : Given an integer, gets sql test from database and runs it.				\n TODO \
-tall: Runs all associated sql tests in related database.						\n TODO \
-tadd: Adds a given test case to the database.									\n\
Functions:																		\n \
one  []		  - Test case for no reason											\n \
b2b  [int]    - calculates bits in bytes										\n \
pali [string] - calculates whether or not a string is a palindrome.";
