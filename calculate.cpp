#include "calculate.hpp"
using namespace std;
std::string calculateBullAndPgia(const std::string choice, const std::string guess) { 
    int bull = 0;
    int pgia = 0;
    int numbers[10];
    for (int i=0;i<10;i++){
        numbers[i]=0;
    }
    for (int i = 0; i<choice.length(); i++) {
        if (choice.at(i) == guess.at(i)) bull++;
        else {
            if (numbers[choice.at(i)-'0']++ < 0) pgia++;
            if (numbers[guess.at(i)-'0']-- > 0) pgia++;
        }
    }
    //delete[]  numbers;
    return to_string(bull) + "," + to_string(pgia);
}
    
