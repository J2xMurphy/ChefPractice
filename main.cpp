#include "main.h"

int main(int argc, char *argv[]){
	init();
	// Temp string in case sql testing is initiated.
	std::string temp;
	std::string argstr[argc];
	deFunct mainarg;
	// A loop through all the arguments provided to tell which
	// values are option keys and which are relevant values
	int i,ix = 0;
	bool use_external = false;
	std::vector<testio> main_tests;
	if (argc>1){
		std::string args[argc+1];
		for(i=1; i<argc;i++){
			args[i] = argv[i]; 
			logger((std::to_string(i)+":"+args[i]));
			
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
		}
		// Prints a few things before starting
		logger("Arguments Read.");
		std::cout << "Verbosity = " << logstats.verbose << std::endl;
		std::cout << "Logger = " << logstats.dolog << std::endl;
		logger("<---Begin Function---> " +argstr[ix-2]);
		
		// Convert any legal input to testio format
		if (use_external == true){
			main_tests = getdb("cuslib/"+mainarg.loc());
			logger("pass: "+std::to_string(main_tests.size()));
			ix = 3;
		}else{
			testio ntio(0,argstr[1],"NULL");
			main_tests.push_back(ntio);
		}
		
		// First level argc checking, for single arg functions
		// A should be case statement for possible arguments.
		for(testio tio:main_tests){
			logger(tio.input);
			if (ix<1){
				sl("No arguments given.");
				logEnd();
			}
			else if (argstr[0] == "one"){
				chef();
				logger("One called");
			}
			//Second level argc checking for double arg functions
			else if (ix<2){
				sl("Not enough arguments given.");
			}
			else if (mainarg.get() == b2b.get()){
				chefb2b(tio.getin());
			}
			else if (mainarg.get() == pali.get()){
				chefpali(tio.getin());
			}
			// If all argc checking fails
			else{
				sl("No valid arguments given.");
			}
		}
	}else{
		sl("No arguments given.\n");
	}
	logEnd();
	return 1;
}