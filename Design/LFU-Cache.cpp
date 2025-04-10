// LC - 460 - HARD - LFU Cache
#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<list>
using namespace std;
class LFUCache{
    int size=0;
    int cap;
    // {key -> Address}
    unordered_map<int,list<vector<int>>::iterator>mp;
    // {Counter->DLL}
    map<int,list<vector<int>>>freq;
    public:
    LFUCache(int capacity){
        this->cap=capacity;
        this->size=0;
    }
    void makeMostFrequentlyUsed(int key){
        auto &vec=(*(mp[key]));
        int val=vec[1],f=vec[2];

        freq[f].erase(mp[key]);
        if(freq[f].empty()) freq.erase(f);

        freq[f+1].push_front(vector<int>({key,val,f+1}));
        mp[key]=freq[f+1].begin();
    }
    int get(int key){
        if(!mp.count(key)) return -1;

        auto &vec=(*(mp[key]));
        int val=vec[1];
        makeMostFrequentlyUsed(key);
        return val;
    }
    void put(int key,int value){
        if(cap==0) return;

        if(mp.count(key)){
            auto &vec=(*(mp[key]));
            vec[1]=value;
            makeMostFrequentlyUsed(key);
        } else if(size<cap){
            size++;
            freq[1].push_front(vector<int>({key,value,1}));
            mp[key]=freq[1].begin();
        } else{
            auto &lru_list=freq.begin()->second;
            int key_delete=lru_list.back()[0];
            lru_list.pop_back();
            mp.erase(key_delete);

            if(lru_list.empty()) freq.erase(freq.begin()->first);

            freq[1].push_front(vector<int>({key,value,1}));
            mp[key]=freq[1].begin();
        }
    }
};