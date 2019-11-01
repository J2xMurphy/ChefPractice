#ifndef CHEFG
#define CHEFG
// Local Include
#include "Byte2Bit/b2b.cpp"
#include "Palindrome/pali.cpp"
#include "clib.h"
// Prep Include
#include <iostream>
#include <string>
// Funcions
void chef();

//Byte2Bit
int chefb2b(std::string istring,std::string ostring);

//Palindrome
int chefpali(std::string istring,std::string ostring);
#endif