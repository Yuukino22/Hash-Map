d#include "HashMap.hpp"
#include <iostream>

namespace
{
    unsigned int initialHash(std::string s)
    {
        int sum = 0;
        for(char c: s)
        {
            sum += int(c);
        }
        return sum;
    }
}


HashMap::HashMap()
    :hashFunction{initialHash}, 
     arr{new Node*[HashMap::INITIAL_BUCKET_COUNT]{nullptr}}, 
     sz{0}, 
     bk{HashMap::INITIAL_BUCKET_COUNT}
{
}

HashMap::HashMap(HashFunction hashFunction)
    :hashFunction{hashFunction}, 
     arr{new Node*[HashMap::INITIAL_BUCKET_COUNT]{nullptr}}, 
     sz{0},
     bk{HashMap::INITIAL_BUCKET_COUNT}
{
}

HashMap::HashMap(const HashMap& hm)
    :hashFunction{hm.hashFunction}, 
     arr{new Node*[hm.bucketCount()]{nullptr}},
     sz{hm.sz},
     bk{hm.bk}
{
    for(int i = 0; i < hm.bk; i++)
    {
        llcopy(arr[i], hm.arr[i]);
    }
}

HashMap::~HashMap()
{
    deleteArr(*this);
}

HashMap& HashMap::operator=(const HashMap& hm)
{
    if (this != &hm)
    {
        hashFunction = hm.hashFunction;

        Node** newArr = new Node*[hm.bk]{nullptr};
        for(int i = 0; i < hm.bk; i++)
        {
            llcopy(newArr[i], hm.arr[i]);
        }
        
        deleteArr(*this);
        sz = hm.sz;
        bk = hm.bk;
        arr = newArr;    
    }

    return *this;
}

void HashMap::add(const std::string& key, const std::string& value)
{
    if(!contains(key))
    {
        sz++;
        if (loadFactor() > 0.8)
        {
            int lbucket = bk;
            bk = bk * 2 + 1;
            Node** newArr = new Node*[bk]{nullptr};
            for(int i = 0; i < lbucket; i++)
            {
                Node* current = arr[i];
                while(current != nullptr)
                {
                    int j = hashFunction(current -> key) % bk;
                    Node* tar = newArr[j];
                    if(tar == nullptr)
                    {
                        newArr[j] = new Node{current -> key, current -> value, nullptr};
                    }
                    else
                    {
                        while(tar -> next != nullptr)
                        {
                            tar = tar -> next;
                        }
                        tar -> next = new Node{current -> key, current -> value, nullptr};
                    }
                    current = current -> next;
                }
            }
            for(int i = 0; i <lbucket; i++)
            {
                Node* current = arr[i];
                while(current != nullptr)
                {
                    Node* n = current -> next;
                    delete current;
                    current = n;
                }
            }
            delete[] arr;
            arr = newArr;
        }
    
        int p = hashFunction(key) % bk;
        Node* current = arr[p];
        if (current == nullptr)
        {
            arr[p] = new Node{key, value, nullptr};
        }
        else
        {
            while(current -> next != nullptr)
            {
                current = current -> next;
            }
            current -> next = new Node{key, value, nullptr};
        }
        
    }

}

bool HashMap::remove(const std::string& key)
{
    bool result =  contains(key);
    if(result)
    {
        int i = hashFunction(key) % bk;
        Node* current = arr[i];
        if (current -> key == key)
        {
            arr[i] = current -> next;
            delete current;
        }
        else
        {
            while(current -> next -> key != key)
            {
                current = current -> next;
            }
            Node* m = current -> next -> next;
            delete current -> next;
            current -> next = m;
        }
        sz--;
    }
    return result;
}

bool HashMap::contains(const std::string& key) const
{
    int i = hashFunction(key) % bk;
    Node* current = arr[i];
    while (current != nullptr)
    {
        if(current -> key == key)
        {
            return true;
        }
        current = current -> next;
    }
    return false;
}

std::string HashMap::value(const std::string& key) const
{
    if(contains(key))
    {
        int i = hashFunction(key) % bk;
        Node* current = arr[i];
        std::string result;
        while (current != nullptr)
        {
            if(current -> key == key)
            {
                result = current -> value;
                break;
            }
            current = current -> next;
        }
        return result;
    }
    else
    {
        return "";
    }
}

void HashMap::clear()
{
    Node** newArr = new Node*[bk]{nullptr};
    deleteArr(*this);
    arr = newArr;
    sz = 0;
}

unsigned int HashMap::size() const
{
    return sz;
}

unsigned int HashMap::bucketCount() const
{
    return bk;
}

double HashMap::loadFactor() const
{
    return double(sz) / double(bk);
}

unsigned int HashMap::maxBucketSize() const
{
    int result = 0;
    for(int i = 0; i < bk; i++)
    {
        int length = 0;
        Node* current = arr[i];
        while(current != nullptr)
        {
            length++;
            current = current -> next;
        }
        if (length > result)
        {
            result = length;
        }
    }
    return result;
}

void HashMap::llcopy(Node* &target, Node* source)
{
    Node* current = source;
    if (current != nullptr)
    {
        target = new Node{current -> key, current -> value, nullptr};
        current = current -> next;
    }
    Node* prev = target;
    while (current != nullptr)
    {
        prev -> next = new Node{current -> key, current -> value, nullptr};
        prev = prev -> next;
        current = current -> next;
    }
}

void HashMap::deleteArr(HashMap& hm)
{
    for(int i = 0; i < hm.bk; i++)
    {
        Node* current = hm.arr[i];
        while(current != nullptr)
        {
            Node* n = current -> next;
            delete current;
            current = n;
        }
    }
    delete[] hm.arr;
}


void HashMap::myprint() const
{
    for(int i = 0; i < bk; i++)
    {
        Node* current = arr[i];
        while(current != nullptr)
        {
            std::cout << current -> key << " ";
            current = current -> next;
        }
        std::cout << "end";
        std::cout << std::endl;
    }
}