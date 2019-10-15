#include "clib.h"

// sl is an absolute logger, despite verbose and logger settings
void sl(std::string message){
	std::cout << message << std::endl;
	logmem += message+"\n";
}
// sl for ints
void sl(int message){
	std::cout << std::to_string(message) << std::endl;
	logmem += std::to_string(message)+"\n";
}


// Normal logger for strings
void logger(std::string message,logStatistics logstats){
	if (logstats.verbose)
		std::cout << message << std::endl;
	if (logstats.dolog)
		logmem += message+"\n";
}
// Normal logger for ints
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
    int error = 0; 
	
	// Open SQL file, return on error.
    error = sqlite3_open("cuslib/Byte2Bit/tests.db", &db); 
    if (error) { 
        std::cerr << "Error when opening database. " << sqlite3_errmsg(db) << std::endl; 
        return "error"; 
    } 
    else
        logger("Successfully opened database."); 
	
	// Get the numer of tests.
	int count = 0;
	count = sqlite3_exec(db, "select count(*) from tests;", getcount, &count, NULL);
	
	// Init testio[count] array, and populate it with tests
	testio tests[count];
	sqlite3_exec(db, "select * from tests;", testnumbers, &tests, NULL);
	
	//Close the database
    sqlite3_close(db); 

	// TODO find a way to return the array without breaking prior code.
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
        logger("Successfully opened database."); 
	return 0;
}

// Gets the sql query into a testio format
static int testnumbers(void* database, int argc, char** argv, char** azColName) 
{ 
	// TODO Set security standards on the argvs
	
	//Transfer a void* to a testio**
	testio *temp = (testio*)database;
	
	// Set tests to sql results
	temp[str2int(argv[0])].id = str2int(argv[0]);
	temp[str2int(argv[0])].input = argv[1];
	temp[str2int(argv[0])].output = argv[2];
	
	//------------------------------------------------
    return 0; 
} 

// For use in count* to return the number of ids for an array.
static int getcount(void* database, int argc, char** argv, char** azColName) 
{
    return str2int(argv[0]); 
} 