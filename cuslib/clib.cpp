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
std::vector<testio> getdb(std::string input){
	std::cout << input <<std::endl;
	sqlite3* db; 
    int error = 0; 
	input += "/tests.db";
	char tstr[input.size()+1];
	strcpy(tstr,input.c_str());
	// Open SQL file, return on error.
    error = sqlite3_open(tstr, &db); 
    if (error) { 
        std::cerr << "Error when opening database. " << sqlite3_errmsg(db) << std::endl; 
		std::vector<testio> nop;
        return nop; 
    } 
    else
        logger("Successfully opened database."); 
	
	// Init testio vector, and populate it with tests
	std::vector<testio> tests;
	sqlite3_exec(db, "select * from tests;", testnumbers, &tests, NULL);
	
	//Close the database
    sqlite3_close(db); 
	logger("Successfully retrieved: "+std::to_string(tests.size())+" tests from database.");
	
	return tests;
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
	
	//Transfer a void* to a vector*
	std::vector<testio> *temp = (std::vector<testio>*) database;
	
	//make a new testio for adding to the vector
	testio ntio(str2int(argv[0]),argv[1],argv[2]);
//	ntio.id = str2int(argv[0]);
//	ntio.input = argv[1];
//	ntio.output = argv[2];
	
	logger(ntio.read());
	//add the testio to the vector
	temp->push_back(ntio);
	//------------------------------------------------
    return 0; 
} 

// For use in count* to return the number of ids for an array.
static int getcount(void* database, int argc, char** argv, char** azColName) 
{
    return str2int(argv[0]); 
} 