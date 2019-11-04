#ifndef CLCP
#define CLCP
#include "cuslib/chef.cpp"
#include "cuslib/clib.cpp"
#include "stdio.h"

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
typedef int (* functiontype)(std::string istring,std::string ostring);

class deFunct{// Class for holding directory data
	private:
	std::string name;
	std::string dir;
	functiontype cusfunc;
	public:
	deFunct(std::string tname, std::string tdir, int (*f)(std::string,std::string)){
		name = tname;
		dir = tdir;
		cusfunc = f;
	}
	
//	Empty initializer for null initialization.
	deFunct(){}
//	returns the terminal input information given dring initialization.
	std::string get(){
		return name;
	}
//	returns the directory information given dring initialization.
//  tables in the sql database files must be called tests.
	std::string loc(){
		return dir;
	}
//	returns the function given in initialization.
	functiontype getfunc(){
		return cusfunc;
	}
};

class settings{// Class for storing settings cleanly
	public:
	bool use_external = false;
	bool all_tests = false;
	bool f_end = false;
	int testnumber = -1;	
};

//void init();
//List of all functions
//To add to list, add a deFunct type, with args
// ([Terminal input], [Code directory], [function to be called])
// Define the preprocessor in the chef.cpp file.
std::vector<deFunct> allFunc;
deFunct b2b("b2b", "Byte2Bit", chefb2b);
deFunct pali("pali", "Palindrome", chefpali);
deFunct asq("asq","aSquare",chefasq);

void init(){
	allFunc.push_back(b2b);
	allFunc.push_back(pali);
	allFunc.push_back(asq);
}

// The help string for -h
std::string help_notice = "Use stuff.											\n \
-v   : Activates Verbose mode, displays information realtime in terminal.		\n \
-l   : Sends more information into the log regarding runtime.					\n \
-t   : Given an integer, gets sql test from database and runs it.				\n \
-tall: Runs all associated sql tests in related database.						\n TODO \
-tadd: Adds a given test case to the database.									\n\
Functions:																		\n \
one  []		  - Test case for no reason											\n \
b2b  [int]    - calculates bits in bytes										\n \
pali [string] - calculates whether or not a string is a palindrome.";
#endif
