#include "chef.h"
//Base function for testing
int chef(std::string istring, std::string ostring){
	sl("No valid functions");
	return 0;
}

// Handles preprocessing of byte2bit
// Tells how many bits are in a byte
int chefb2b(std::string istring, std::string ostring){
	ostring = (ostring=="NULL") ? "0" : ostring;
	logger("Recieved as Byte2Bit");
	int newint = str2int(istring);
	if (newint<0){
		sl("Invalid number given.");
		return 0;
	}
	int finint = byte2bit(newint);
	sl(std::to_string(newint) + " bytes are equivalent to " + std::to_string(finint) + " bits of space.");
	
	return finint == str2int(ostring);
}

//Handles preprocessing of palindrome
//Tells if a string is a palindrome
int chefpali(std::string istring, std::string ostring){
	ostring = (ostring=="NULL") ? "true": ostring;
	logger("Recieved as Palindrome");
	std::cout << ostring << std::endl;
	if (isPalindrome(istring)){
		sl(istring + " is a palindrome.");
		if (ostring == "true"){
			return 1;
		}
		return 0;
	}else{
		sl(istring + " is not a palindrome.");
		if (ostring == "false"){
			return 1;
		}
		return 0;
	}
}

//Handles preprocessing of aSquare
//Tells if a number is a squared number
int chefasq(std::string istring, std::string ostring) {
	ostring = (ostring=="NULL") ? "-1" : ostring;
	logger("Recieved as aSquare");
	
	int newint = str2int(istring);
	if (newint<0){
		sl("Invalid number given.");
		return 0;
	}
	newint = aSquare(newint);

	if (newint==-1){
		sl((istring+"is not a square number."));
		if (ostring=="-1") 
			return 1;
		return 0;
	}
	else{
		sl((istring+" is "+ std::to_string(newint) +" squared."));
		if ((newint != str2int(ostring)) and (ostring!="-1")) {
			logger("Error: expected root : " + ostring + "\nDerived value : "+ std::to_string(newint));
			return 0;
			}
		return 1;
		
	}
}