#pragma once
#include "Guesser.hpp"
#include<list>
using std::string;
/**
 * SmartGuesser is a guesser that always smart
 */

	class SmartGuesser: public bullpgia::Guesser {
			std::list<std::string> all_option;
		
		public:
			void learn(std::string bull_pgia_ans); 
         
  	  	    void startNewGame(unsigned int length);
		
			string guess();
};

