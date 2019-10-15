#ifndef CLIBG
#define CLIBG
// Include
#include "stdio.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sqlite3.h>

// A class for storing sql testing information.
class testio{
	public:
		int id = -1; //			   id of test
		std::string input = "";//  input string of test
		std::string output = "";// Desired output of test
};

// A class for logging settings.
class logStatistics{
	public:
		bool verbose = false; // Whether logs should be posted in terminal.
		bool dolog = false; //Whether to print logger contents to a log file afterwards. 
};

// global log memory and log settings
static std::string logmem = ""; // Global log string
static logStatistics logstats;  // Global log setting variables

// sl is an absolute logger, despite verbose and logger settings  -- "SUPER LOGGER"
void sl(std::string message="");  // SL for strings
void sl(int message);			  // SL for integers

// Logger for strings or ints, logstats settings apply -- "Normal logger"
// Can take custom settings
void logger(std::string message = "",logStatistics = logstats);  //logger for strings
void logger(int message,logStatistics = logstats);				 //logger for integers

//Get tests from sql database, Chonky code
std::string getdb(std::string input);

// logend carries out writing log memory to finishing log
void logEnd();

//Converts string to int
int str2int(std::string="0");


//SQL wrappers ---- INACTIVE
int resql_open(sqlite3* db);


// Kinda stolen from:
// https://www.geeksforgeeks.org/sql-using-c-c-and-sqlite/

// An abstraction to get the count of items in a sql query before initializing
// an array.
static int getcount(void* database, int argc, char** argv, char** azColName);

// Test numbers passes in all the information from
// the select * from xxx database and returns it in testio[] format.
static int testnumbers(void* database, int argc, char** argv, char** azColName);
#endif
