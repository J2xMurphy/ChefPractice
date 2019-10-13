#ifndef CLIBG
#define CLIBG

// Local Include
#include "stdio.h"
#include <string>

// Prep Include
#include <fstream>
#include <iostream>
#include <sqlite3.h>
// Callback is what seems to execute when the db is queried
// I should be able to edit it as long as its in this format
/*int sqlite3_exec(
  sqlite3*,                                  	 An open database 
  const char *sql,                           	 SQL to be evaluated 
  int (*callback)(void*,int,char**,char**),  	 Callback function 
  void *,                                    	 1st argument to callback 
  char **errmsg                              	 Error msg written here 
);
*/

// Stolen from:
// https://www.geeksforgeeks.org/sql-using-c-c-and-sqlite/
static int callback(void* database, int argc, char** argv, char** azColName) 
{ 
	std::cout << "oll3." << std::endl; 
	
    int i; 
    fprintf(stderr, "%s: ", (const char*)database); 
	
	std::cout << "oll4." << std::endl; 
	
    for (i = 0; i < argc; i++) { 
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL"); 
    } 
	
	std::cout << "oll5." << std::endl; 
  
    printf("\n"); 
    return 0; 
} 

class logStatistics{
	public:
	bool verbose = false; // Whether logs should be posted in terminal.
	bool dolog = false; //Whether to print logger contents to a log file afterwards. 
};

// global log memory and log settings
static std::string logmem = "";
static logStatistics logstats;

// sl is an absolute logger, despite verbose and logger settings
void sl(std::string message="");
void sl(int message);

// Logger for strings or ints
void logger(std::string message = "",logStatistics = logstats);
void logger(int message,logStatistics = logstats);

//Get tests from sql database
std::string getdb(std::string input);

// logend carries out writing log memory to finishing log
void logEnd();

int str2int(std::string="0");


//SQL wrappers
int resql_open(sqlite3* db);
#endif
