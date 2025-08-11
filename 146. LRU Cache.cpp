#include<bits/stdc++.h>
using namespace std;

class LRUCache
{
public:
    int cap;
    list<pair<int , int >>cache;
    unordered_map<int,list<pair<int,int>>>mp;
    LRUCache(int capacity)
    {
        cap = capacity;
    }
    int get(int key){
        if(mp.find(key) == mp.end()) return -1;
        // Move this node to front
        auto it = mp[key];
        int value = it->second;
        cache.erase(it);
        cache.push_front({key,value});
        mp[key] = cache.begin();
        return value;
    }
    void put(int key, int value){
        // If key exists , remove old
        if(mp.find(key)!=mp.end()){
            cache.erase(mp[key]);
        }
        // if cache full , remove LRU
        else if((int)cache.size()==cap){
            auto last = cache.back();
            mp.erase(last.first);
            cache.pop_back();
        }
        // Insert at front
        cache.push_back({key, value});
        mp[key] = cache.begin();
    }
};
