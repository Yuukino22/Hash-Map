#ifndef DECIDE_HPP
#define DECIDE_HPP


#include "command.hpp"
#include "HashMap.hpp"
#include "process.hpp"

std::string string_decide(Command& c, HashMap& hm, bool& debug);

int int_decide(Command& c, HashMap& hm, bool& debug);

double double_decide(Command& c, HashMap& hm, bool& debug);

#endif