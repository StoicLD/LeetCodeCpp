//
// Created by lidong on 2020/6/13.
//

#ifndef LEETCODECPP_INSERTDELETEGETRANDOM_380_H
#define LEETCODECPP_INSERTDELETEGETRANDOM_380_H

#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;

class InsertDeleteGetRandom_380
{
public:
    unordered_map<int, int> hashMap;
    vector<int> keys;
    /** Initialize your data structure here. */
    InsertDeleteGetRandom_380()
    {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if(hashMap.find(val) != hashMap.end())
            return false;
        keys.push_back(val);
        hashMap.insert(make_pair(val, keys.size() - 1));
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        if(hashMap.find(val) != hashMap.end())
        {
            int index = hashMap[val];
            swap(keys[index], keys[keys.size() - 1]);
            hashMap[keys[index]] = index;
            keys.pop_back();
            hashMap.erase(val);
            return true;
        }
        return false;
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        return keys[rand()%keys.size()];
    }
};


#endif //LEETCODECPP_INSERTDELETEGETRANDOM_380_H
