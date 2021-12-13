#include "decide.hpp"

std::string string_decide(Command& c, HashMap& hm, bool& debug)
{
    if (c.getc0() == "CREATE" && c.getc1() != "" && c.getc2() != "")
    {
        return create(c, hm);
    }
    if (c.getc0() == "LOGIN" && c.getc1() != "" && c.getc2() != "")
    {
        return login(c, hm);
    }
    if (c.getc0() == "REMOVE" && c.getc1() != "" && c.getc2() == "")
    {
        return remove(c, hm);
    }
    if (c.getc0() == "CLEAR" && c.getc1() == "" && c.getc2() == "")
    {
        return clear(hm);
    }
    if (c.getc0() == "QUIT" && c.getc1() == "" && c.getc2() == "")
    {
        return quit();
    }
    if (c.getc0() == "DEBUG" && c.getc1() == "ON" && c.getc2() == "")
    {
        return debug_on(debug);
    }
    if (c.getc0() == "DEBUG" && c.getc1() == "OFF" && c.getc2() == "")
    {
        return debug_off(debug);
    }
    return "INVALID";
}

int int_decide(Command& c, HashMap& hm, bool& debug)
{
    if (c.getc0() == "LOGIN" && c.getc1() == "COUNT" && c.getc2() == "" && debug)
    {
        return login_count(hm);
    }
    if (c.getc0() == "BUCKET" && c.getc1() == "COUNT" && c.getc2() == "" && debug)
    {
        return bucket_count(hm);
    }
    if (c.getc0() == "MAX" && c.getc1() == "BUCKET" && c.getc2() == "SIZE" && debug)
    {
        return max_bucket_size(hm);
    }
    return -1;
}

double double_decide(Command& c, HashMap& hm, bool& debug)
{
    if (c.getc0() == "LOAD" && c.getc1() == "FACTOR" && c.getc2() == "" && debug)
    {
        return load_factor(hm);
    }
    return -1;
}