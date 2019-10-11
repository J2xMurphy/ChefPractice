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
int str2int(std::string input){
	int output = stoi(input);
	return output;
}