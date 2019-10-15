#include "chef.h"
//Base function for testing
void chef(){
	logger("works");
}

// Handles preprocessing of byte2bit
// Tells how many bits are in a byte
void chefb2b(std::string istring[]){
	logger("Recieved as Byte2Bit");
	int newint = str2int(istring[1]);
	newint = byte2bit(newint);
	sl(istring[1] + " bytes are equivalent to " + std::to_string(newint) + " bits of space.");
	return;
}

//Handles preprocessing of palindrome
//Tells if a string is a palindrome
void chefpali(std::string istring[]){
	logger("Recieved as Palindrome");
	if (isPalindrome(istring[1]))
		sl(istring[1] + " is a palindrome.");
	else
		sl(istring[1] + " is not a palindrome.");
	return;
}