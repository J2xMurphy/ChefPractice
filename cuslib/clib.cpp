#include "clib.h"

// sl is an absolute logger, despite verbose and logger settings
void sl(std::string message){
	std::cout << message << std::endl;
	logmem += message+"\n";
}
void sl(int message){
	std::cout << std::to_string(message) << std::endl;
	logmem += std::to_string(message)+"\n";
}


// Logger for strings or ints
void logger(std::string message,logStatistics logstats){
	if (logstats.verbose)
		std::cout << message << std::endl;
	if (logstats.dolog)
		logmem += message+"\n";
}
void logger(int message,logStatistics logstats){
	if (logstats.verbose)
		std::cout << std::to_string(message) << std::endl;
	if (logstats.dolog)
		logmem += std::to_string(message)+"\n";
}

// logend carries out writing log memory to finishing log
void logEnd(){
	std::fstream log;
	log.open("log.txt", std::fstream::in | std::fstream::out | std::fstream::trunc);
	log.write(logmem.c_str(),logmem.size());
	log.close();
}

// get tests from sql database
std::string getdb(std::string input){
	sqlite3* db; 
	
///	resql_open(db);

   
    int error = 0; 
    error = sqlite3_open("cuslib/Byte2Bit/tests.db", &db); 
  
    if (error) { 
        std::cerr << "Error when opening database. " << sqlite3_errmsg(db) << std::endl; 
        return "error"; 
    } 
    else
        std::cout << "Successfully opened database." << std::endl; 
	

	std::cout << "oll1. crashing in exec" << std::endl; 
	sqlite3_exec(db, "select * from tests;", callback, NULL, NULL);
	std::cout << "oll2." << std::endl; 
    sqlite3_close(db); 
	return "Hello World";
}

// convert string to integer
int str2int(std::string input){
	int output = stoi(input);
	return output;
}


//SQL wrappers
int resql_open(sqlite3* db){
    int error = 0; 
    error = sqlite3_open("cuslib/Byte2Bit/tests.db", &db); 
  
    if (error) { 
        std::cerr << "Error when opening database. " << sqlite3_errmsg(db) << std::endl; 
        return 1; 
    } 
    else
        std::cout << "Successfully opened database." << std::endl; 
	return 0;
}