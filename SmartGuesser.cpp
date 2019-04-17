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
	//std::vector<unsigned long int> delet_vec;
	//std::cout<<"nuber of del"<<std::endl;
	list<string>::iterator i=all_option.begin();
	//unsigned int counter=0;
	//unsigned int all_option_size = all_option.size();
	//std::cout<<"sec guess"<<_guess<<std::endl;
	 while (i != all_option.end()) {
       string curr_result =calculateBullAndPgia(*i, _guess); 
	   //std::cout<<"second bullPgia: "<<curr_result<<" on: "<<*i<<"<-cho   guess->"<<_guess<<std::endl;//<<"  "<<"guess: "<<guess<<std::endl;
		
	   //std::cout<<"i: "<<*i<<"guess: "<<_guess<< " aftercompare between " << bull_pgia_ans << "," << curr_result << " = " << bull_pgia_ans.compare(curr_result) << std::endl;
	   //std::cout<<"sec: "<<curr_result<<std::endl;
	   if (bull_pgia_ans.compare(curr_result)!=0){
		    //std::cout<<bull_pgia_ans<<"  " <<curr_result<<std::endl;
			i=all_option.erase(i);
			//i++;
			//std::cout<<*i<<std::endl;
		}
		else i++;
		//counter++;
	 }
	//std::cout<<"size of list after delete: "<<all_option.size()<<std::endl;
	//if (all_option.size()==1) std::cout<<"the last: "<<all_option.front()<<std::endl;
}
void SmartGuesser::startNewGame(unsigned int length){
	bullpgia::Guesser::startNewGame(length);
	//_guess = "0011";
	unsigned int max = 1;
	for (int i =0 ;i<length;i++){
		max*=10;
	}
	for ( unsigned int i=0;i<max;i++){
		std::stringstream ss;
		ss << std::setw(length) << std::setfill('0') << i;
		std::string s = ss.str();
		all_option.push_front(s);
		//possible_guess.push_back("jk");
	}
	//cout<<all_option.size()<<" start"<<endl;
}

std::string SmartGuesser::guess() {
	if (all_option.size()==1) {//the right answer!
		_guess = all_option.front();
		return _guess;
	}
	std::string r="";
	/*if (all_option.size()==pow(10,length)) {//the first guess in the game
		for (uint i=0; i < this->length; ++i) {
			char c = '0' + i+1;
			r += c;
		}
		_guess = r;
		//cout<<" start"<<endl;
		return r;
	}*/
	
	for (uint i=0; i < this->length; ++i) {//random choice from all posible options
		char c = '0' + (rand()%10);
		r += c;
	}
	_guess = r;
	//_guess=all_option(rand()%all_option.size()];
	//cout<<_guess<<" guess"<<endl;
	return r;
}

//void SmartGuesser::learn(std::string _guess) {
	
//}
