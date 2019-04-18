#include "SmartGuesser.hpp"
#include "Guesser.hpp"
#include "calculate.hpp"
#include <stdlib.h>
#include <sstream>
#include <iomanip>
#include <math.h>
#include<list>
using namespace std;

void SmartGuesser::learn(const string bull_pgia_ans) { 
	list<string>::iterator i=all_option.begin();
	 while (i != all_option.end()) {
       string curr_result =calculateBullAndPgia(*i, _guess); 
	   if (bull_pgia_ans.compare(curr_result)!=0){
			i=all_option.erase(i);
		}
		else i++;
	 }
}
void SmartGuesser::startNewGame(unsigned int length){
	all_option.clear();
	bullpgia::Guesser::startNewGame(length);
	unsigned int max = pow(10,length);

	for ( unsigned int i=0;i<max;i++){
		std::stringstream ss;
		ss << std::setw(length) << std::setfill('0') << i;
		std::string s = ss.str();
		all_option.push_front(s);
	}
}

std::string SmartGuesser::guess() {
	//the first guess in the game
	std::string r="";
	if (all_option.size()==pow(10,length)) {
		for (uint i=0; i < this->length; ++i) {
			char c = '0' + i+1;
			r += c;
		}
		_guess = r;
		return r;
	}
	//random choice from all_option after filtering
	list<string>::iterator i=all_option.begin();
	if (all_option.size()>1)
		advance(i,rand()%(all_option.size()-1));
	_guess = *i;
	return _guess;
}

/*
for (int i =0;i<50;i++){
		std::string guess="";
		int min = 10000;
		std::string minGuess;
		std::string bull_pgia_ans;
		for (uint i=0; i < this->length; ++i) {//random choice from all posible options
			char c = '0' + (rand()%10);
			guess += c;
		}
		for (int bull=0;bull<=length;bull++){//all the option for bull and pgia
			for (int pgia=0;pgia<=length;pgia++){
				bull_pgia_ans = to_string(bull)+","+to_string(pgia);
				int counter =0;
				list<string>::iterator i=all_option.begin();
				while (i != all_option.end()) {
       				string curr_result =calculateBullAndPgia(*i, guess); 
						if (bull_pgia_ans.compare(curr_result)!=0)
							counter++;
				}
				if (counter < min) {
					min = counter;	
				}
			}

		}
		
	}*/
