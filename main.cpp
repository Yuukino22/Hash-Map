#include "HashMap.hpp"
#include "command.hpp"
#include "decide.hpp"
#include "generate.hpp"

#include <iostream>
#include <string>

int main()
{
    HashMap hm;
    bool debug = false;
    while (true)
    {
        std::string input;
        std::getline(std::cin, input);
        Command c = generate_command(input);
        if (c.getc0() == "CREATE" || c.getc0() == "REMOVE" || c.getc0() == "CLEAR"
        || c.getc0() == "QUIT" || c.getc0() == "DEBUG")
        {
            std::cout << string_decide(c, hm, debug) << std::endl;
            if (c.getc0() == "QUIT" && c.getc1() == "" && c.getc2() == "")
            {
                break;
            }
        }
        else if (c.getc0() == "LOGIN")
        {
            if (c.getc1() != "" && c.getc2() != "")
            {
                std::cout << string_decide(c, hm, debug) << std::endl;
            }
            else if (c.getc1() == "COUNT")
            {
                int result;
                result = int_decide(c, hm, debug);
                if (result != -1)
                {
                    std::cout << result << std::endl;
                }
                else
                {
                    std::cout << "INVALID" << std::endl;
                }
            }
            else
            {
                std::cout << "INVALID" << std::endl;
            }
            
        }
        else if (c.getc0() == "BUCKET" || c.getc0() == "MAX")
        {
            int r = int_decide(c, hm, debug);
            if (r == -1)
            {
                std::cout << "INVALID" << std::endl;
            }
            else
            {
                std::cout << r << std::endl;
            }
            
        }
        else if (c.getc0() == "LOAD")
        {
            double d = double_decide(c, hm, debug);
            if(d == -1)
            {
                std::cout << "INVALID" << std::endl;
            }
            else
            {
                std::cout << d << std::endl;
            }
            
        }
        else
        {
            std::cout << "INVALID" << std::endl;
        }
    }
    return 0;
}

