#include "chef.h"
//Base function for testing
void chef(){
	logger("works");
}

// Handles preprocessing of byte2bit
// Tells how many bits are in a byte
int chefb2b(std::string istring){
	logger("Recieved as Byte2Bit");
	int newint = str2int(istring);
	newint = byte2bit(newint);
	sl(istring + " bytes are equivalent to " + std::to_string(newint) + " bits of space.");
	return newint;
}

//Handles preprocessing of palindrome
//Tells if a string is a palindrome
int chefpali(std::string istring){
	logger("Recieved as Palindrome");
	if (isPalindrome(istring)){
		sl(istring + " is a palindrome.");
		return 1;
	}else{
		sl(istring + " is not a palindrome.");
		return 0;
	}
}