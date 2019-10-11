#include "pali.h"

bool isPalindrome(std::string word){
	std::locale loc;
	std::string nstring= "";
	
	//sets all letters in string to lower case.
	for (int i=0;i<word.size();i++){
		nstring+=std::tolower(word.at(word.size()-1-i),loc);
		logger(("\n%c",word.at(i)));
	}
	
	//creates a new string based on a per letter basis from the old one.
	std::string ostring="";
	for (int i=0;i<word.size();i++){
		ostring+=std::tolower(word.at(i),loc);
		logger(("\n%c",word.at(i)));
	}
	
	logger(("\n%s..",nstring.c_str()));
	
	// if the new string and old string are the same, its 1 else 0
	return ostring == nstring;
}
