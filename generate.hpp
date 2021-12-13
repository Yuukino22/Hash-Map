//generate.hpp

#ifndef GENERATE_HPP
#define GENERATE_HPP

#include "command.hpp"

//return the command if the input contains *no* *more* *than*
//three words.
//return the command if the *first* word is correct.
//for other words, check will be in other files.
Command generate_command(std::string input);


#endif