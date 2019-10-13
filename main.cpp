#include "main.h"

int main(int argc, char *argv[]){
	// Temp string in case sql testing is initiated.
	std::string temp;
	std::string argstr[argc];
	// A loop through all the arguments provided to tell which
	// values are option keys and which are relevant values
	int i = 0;
	int ix = 0;
	
	if (argc>1){
		std::string args[argc+1];
		for(i=1; i<argc;i++){
			args[i] = argv[i]; 
			logger((std::to_string(i)+":"+args[i]));
			
			// If -v is given prints all logs to the terminal in runtime.
			if (args[i] == "-v"){
				logstats.verbose = true;
				std::cout << "Verbosity = " << logstats.verbose << std::endl;
			}
			
			// If -l is given, saves a log of terminal after runtime.
			else if (args[i] == "-l"){
				logstats.dolog = true;
				std::cout << "Logger = " << logstats.dolog << std::endl;
			}
			
			// If -h is given, display help and quit.
			else if (args[i] == "-h"){
				std::cout << help_notice << std::endl;
				return 1;
			}
			
			else if (args[i] == "-t"){
				std::cout << "Sql testing initiated." << std::endl;
				temp = getdb("no");
				std::cout << temp << std::endl;
				return 1;
			}
			
			// If not a option key, saves arg to list.
			else{
				argstr[ix] += argv[i];
				ix++;
			}
		}
		// Prints a few things before starting
		logger("Arguments Read.");
		std::cout << "Verbosity = " << logstats.verbose << std::endl;
		std::cout << "Logger = " << logstats.dolog << std::endl;
		std::string tutu = argv[i-1];
		logger("<---Begin Function---> " +argstr[ix-2]);
	
		// First level argc checking, for single arg functions
		// A should be case statement for possible arguments.
		if (ix<1){
			sl("No arguments given.");
			logEnd();
			return 0;
		}
		if (argstr[ix-1] == "one"){
			chef();
			logger("One called");
			logEnd();
			return 0;
		}
	
		//Second level argc checking for double arg functions
		if (ix<2){
			sl("Not enough arguments given.");
			logEnd();
			return 0;
		}
		if (argstr[ix-2] == "b2b"){
			chefb2b(argstr);
			logEnd();
			return 0;
		}
		if (argstr[ix-2] == "pali"){
			chefpali(argstr);
			logEnd();
			return 0;
		}
		
		}else{
		sl("No arguments given.\n");
	}
	logEnd();
}
