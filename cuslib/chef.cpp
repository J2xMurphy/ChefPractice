#include "chef.h"
//Base function for testing
void chef(){
	logger("works");
}

// Handles preprocessing of byte2bit
// Tells how many bits are in a byte
int chefb2b(std::string istring, std::string ostring){
	ostring = (ostring=="NULL") ? "0" : ostring;
	logger("Recieved as Byte2Bit");
	int newint = str2int(istring);
	newint = byte2bit(newint);
	sl(istring + " bytes are equivalent to " + std::to_string(newint) + " bits of space.");
	return newint == str2int(ostring);
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
	ostring = (ostring=="NULL") ? "0" : ostring;
	logger("Recieved as aSquare");
	
	int newint = str2int(istring);
	newint = aSquare(newint);

	if (newint==-1){
		sl((istring+"is not a square number."));
		if (ostring=="-1") 
			return 1;
		return 0;
	}
	else{
		sl((istring+" is "+ std::to_string(newint) +" squared."));
		if (newint != str2int(ostring)) {
			logger("Error: expected root : " + ostring + "\nDerived value : "+ std::to_string(newint));
			return 0;
			}
		return 1;
		
	}
}