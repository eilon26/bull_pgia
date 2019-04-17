#ifndef GUESSER_HPP
#define GUESSER_HPP
#include <iostream>
#include "calculate.hpp"

namespace bullpgia {
class Guesser {
protected:
    unsigned int length;
    std::string _guess;
public:
    virtual std::string guess() = 0;
    virtual void learn(const std::string bull_pgia_ans) { 
         }
    virtual void startNewGame(unsigned int length) { this->length = length; }

};
}
#endif