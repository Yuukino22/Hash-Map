#include "generate.hpp"

Command generate_command(std::string input)
{
    std::string arr[3] = {""};
    int now = -1;
    bool flag = false;
    for(char i: input)
    {
        if(i != ' ' && flag == true)
        {
            arr[now] = arr[now] + i;
        }

        if(i != ' ' && flag == false)
        {
            now++;
            if(now >= 3)
            {
                return Command{"INVALID", "", ""};
            }
            arr[now] = arr[now] + i;
            flag = true;
        }
        
        if(i == ' ')
        {
            flag = false;
        }
    }
    if (arr[0] == "CREATE" || arr[0] == "LOGIN" || arr[0] == "REMOVE"
        || arr[0] == "CLEAR" || arr[0] == "QUIT" || arr[0] == "DEBUG"
        || arr[0] == "BUCKET" || arr[0] == "LOAD" || arr[0] == "MAX")
    {
        return Command{arr[0], arr[1], arr[2]};
    }
    else
    {
        return Command{"INVALID","", ""};
    }
    
}