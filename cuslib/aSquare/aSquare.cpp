#include "aSquare.h"

int aSquare(int input){
	
	float temp = std::sqrt(input);
	input = (std::fmod(temp,1)==0) ? temp : -1;
	
	logger(">"+std::to_string(temp));
	logger(">>"+std::to_string(std::fmod(temp,1)));
	logger(">>>"+std::to_string(input));
	
	return input;
}