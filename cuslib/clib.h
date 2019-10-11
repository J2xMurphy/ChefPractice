#ifndef CLIBG
#define CLIBG

// Local Include
#include "stdio.h"
#include <string>

// Prep Include
#include <fstream>
#include <iostream>

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

// logend carries out writing log memory to finishing log
void logEnd();

int str2int(std::string="0");
#endif
