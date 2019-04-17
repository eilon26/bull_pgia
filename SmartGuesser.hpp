#pragma once
#include "Guesser.hpp"
#include<list>
using std::string;
/**
 * SmartGuesser is a guesser that always smart
 */
class SmartGuesser: public bullpgia::Guesser {
		//string myConstantString;
		std::list<std::string> all_option;
		//std::list<std::string> possible_guess;
	public:
		//SmartGuesser() = default;
		//SmartGuesser(const string& constantString) { myConstantString = constantString; }
		void learn(std::string bull_pgia_ans)override; 
         
        void startNewGame(unsigned int length)override;
		
		string guess() override;
};

