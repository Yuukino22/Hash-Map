#include "process.hpp"

std::string create(Command& c, HashMap& hm)
{
    if(hm.contains(c.getc1()))
    {
        return "EXISTS";
    }
    else
    {
        hm.add(c.getc1(), c.getc2());
        return "CREATED";
    }
}

std::string login(Command& c, HashMap& hm)
{
    if(hm.contains(c.getc1()))
    {
        if(hm.value(c.getc1()) == c.getc2())
        {
            return "SUCCEEDED";
        }
    }
    return "FAILED";
}

std::string remove(Command& c, HashMap& hm)
{
    if (hm.contains(c.getc1()))
    {
        hm.remove(c.getc1());
        return "REMOVED";
    }
    return "NONEXISTENT";
}

std::string clear(HashMap& hm)
{
   hm.clear();
   return "CLEARED";
}

std::string quit()
{
    return "GOODBYE";
}

std::string debug_on(bool& debug)
{
    if(debug)
    {
        return "ON ALREADY";
    }
    else
    {
        debug = true;
        return "ON NOW";
    }
}

std::string debug_off(bool& debug)
{
    if(debug)
    {
        debug = false;
        return "OFF NOW";
    }
    else
    {
        return "OFF ALREADY";
    }
}

int login_count(HashMap& hm)
{
    return hm.size();
}

int bucket_count(HashMap& hm)
{
    return hm.bucketCount();
}

double load_factor(HashMap& hm)
{
    return hm.loadFactor();
}

int max_bucket_size(HashMap& hm)
{
    return hm.maxBucketSize();
}