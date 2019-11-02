#include "main.h"

int main(int argc, char *argv[]){
	init();
	// Temp string in case sql testing is initiated.
	std::string temp;
	std::string argstr[argc];
	deFunct mainarg;
	// A loop through all the arguments provided to tell which
	// values are option keys and which are relevant values
	int i = 0;
	int ix = 0;
	int t_pass = 0;
	bool use_external = false;
	std::vector<testio> main_tests;
	if (argc>1){
		std::string args[argc+1];
		for(i=1; i<argc;i++){
			args[i] = argv[i]; 
			// If -v is given prints all logs to the terminal in runtime.
			if (args[i] == "-v"){
				logstats.verbose = true;
				std::cout << "Verbosity = " << logstats.verbose << std::endl;
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
			
			// if -t is given, go into SQL mode and execute test
			else if (args[i] == "-t"){
				logger("Sql testing initiated.");
				use_external = true;
			}
			
			// If not a flag, saves arg to list for arg selection.
			else{
				for (deFunct func: allFunc){
					if (argv[i]==func.get())
						mainarg = func;
				}
				argstr[ix] += argv[i];
				ix++;
			}
			logger((std::to_string(i)+":"+args[i]));
		}
		// Prints a few things before starting
		logger("Arguments Read.");
		std::cout << "Verbosity = " << logstats.verbose << std::endl;
		std::cout << "Logger = " << logstats.dolog << std::endl;
		logger("<---Begin Function---> " +argstr[ix-2]);
		
		// Convert any legal input to testio format
		if (use_external == true){
			main_tests = getdb("cuslib/"+mainarg.loc());
			logger("Continuing with "+std::to_string(main_tests.size())+" tests on main.");
			ix = 3;
		}else{
			testio ntio(0,argstr[1],"NULL");
			if (ix >= 3)
				ntio.output = argstr[2];
			main_tests.push_back(ntio);
		}
		
		logger("ix value:" +std::to_string(ix));
		// First level argc checking, for single arg functions
		// A should be case statement for possible arguments.
		for(testio tio:main_tests){
			//logger(tio.input);
			if (ix == 0){
				sl("No inputs detected.");
				logEnd();
			}
			else if (ix == 1){
				sl("No arguments given.");
				logEnd();
			}
			else if (ix == 2){
				mainarg.getfunc()(tio.input,tio.output);
			}
			else if (ix == 3){
				t_pass+=mainarg.getfunc()(tio.input,tio.output);
			}
		}
	}else{
		sl("No arguments given.\n");
	}
	if (ix == 3)
		sl(std::to_string(t_pass)+ " of "+ std::to_string(main_tests.size())+ " tests passed.");
	logEnd();
	return 1;
}