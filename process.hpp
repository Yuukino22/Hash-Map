//process.hpp
//
//It includes functions that will be called if the command
//is *correct* and *valid*.

#ifndef PROCESS_HPP
#define PROCESS_HPP

#include "command.hpp"
#include "HashMap.hpp"

//create key/value in hashmap
//return CREATED/EXISTS
std::string create(Command& c, HashMap& hm);

//check whether key/value are correct
//return SUCCEEDED/FAILED
std::string login(Command& c, HashMap& hm);

//remove key from hashmap
//return REMOVED/NONEXISTENT
std::string remove(Command& c, HashMap& hm);

//clear every key/value in hashmap
//return CLEARED
std::string clear(HashMap& hm);

//quit the program
//return GOODBYE
std::string quit();

//debug on
//return ON NOW/ON ALREADY
std::string debug_on(bool& debug);

//debug off
//return OFF NOW/OFF ALREADY
std::string debug_off(bool& debug);

//return the number of key/value in hashmap
int login_count(HashMap& hm);

//return the number of buckets
int bucket_count(HashMap& hm);

//return the load factor
double load_factor(HashMap& hm);

//return the max bucket size
int max_bucket_size(HashMap& hm);




#endif