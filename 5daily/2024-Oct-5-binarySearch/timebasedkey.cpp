#include <bits/stdc++.h>
using namespace std;
/*
Design a time-based key-value data structure that can store multiple values for the same key at different time stamps and retrieve the key's value at a certain timestamp.

Implement the TimeMap class:

TimeMap() Initializes the object of the data structure.
void set(String key, String value, int timestamp) Stores the key key with the value value at the given time timestamp.
String get(String key, int timestamp) Returns a value such that set was called previously, with timestamp_prev <= timestamp. If there are multiple such values, it returns the value associated with the largest timestamp_prev. If there are no values, it returns "".

*/
class TimeMap
{
private:
    std::unordered_map<std::string, std::map<int, std::string>> mp;

public:
    TimeMap() {}

    void set(std::string key, std::string value, int timestamp)
    {
        mp[key][timestamp] = value;
    }

    std::string get(std::string key, int timestamp)
    {
        auto it = mp[key].upper_bound(timestamp);
        return it == mp[key].begin() ? "" : std::prev(it)->second;
    }
};
/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */