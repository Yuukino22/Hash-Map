#include "command.hpp"

Command::Command(const std::string& c0, const std::string& c1, const std::string& c2)
    :command0{c0}, command1{c1}, command2{c2}
{
}

std::string Command::getc0() const
{
    return command0;
}

std::string Command::getc1() const
{
    return command1;
}

std::string Command::getc2() const
{
    return command2;
}