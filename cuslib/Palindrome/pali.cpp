#include "pali.h"

bool isPalindrome(std::string word){
	std::locale loc;
	std::string nstring= "";
	//sets all letters in string to lower case.
	for (int i=0;i<word.size();i++){
		nstring+=std::tolower(word.at(word.size()-1-i),loc);
		//logger(("\n%c",nstring.at(i)));
	}
	
	//creates a new reverse string based on a per letter basis from the old one.
	std::string ostring="";
	int t = 0;
	for (int i = word.size()-1; i>=0; i--){
		ostring+=nstring.at(i);
	}
	
	// if the new string and old string are the same, its 1 else 0
	return ostring == nstring;
}
