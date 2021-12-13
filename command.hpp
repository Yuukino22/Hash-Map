//command.hpp
//
//This is a class declaration for the Command class.
//Command Class has three member variables:
//
//0. the first word
//1. the second word
//2. the last word

#ifndef COMMAND_HPP
#define COMMAND_HPP
#include <string>

class Command
{
public:
    //Initialize
    Command(const std::string& c0, 
            const std::string& c1, 
            const std::string& c2);

    //return the first word
    std::string getc0() const;

    //return the second word
    std::string getc1() const;

    //return the third word
    std::string getc2() const;

private:
    std::string command0;
    std::string command1;
    std::string command2;
};


#endif