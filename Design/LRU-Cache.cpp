// LC - 146 - Medium - LRU Cache
#include<iostream>
#include<list>
#include<map>
using namespace std;
class LRUCache{
    int cap;
    list<int>dll;
    map<int,pair<list<int>::iterator,int>>mp;
    public:
    LRUCache(int capacity){
        this->cap=capacity;
    }
    // Pushing in Front
    void makeMostRecentlyUsed(int key){
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first=dll.begin();
    }
    int get(int key){
        if(!mp.count(key)) return -1;

        makeMostRecentlyUsed(key);
        return mp[key].second;
    }
    void put(int key,int value){
        if(mp.count(key)){
            mp[key].second=value;
            makeMostRecentlyUsed(key);
        } else{
            dll.push_front(key);
            mp[key].first=dll.begin();
            cap--;
        }
        if(cap<0){
            mp.erase(dll.back());
            dll.pop_back();
            cap++;
        }
    }
};