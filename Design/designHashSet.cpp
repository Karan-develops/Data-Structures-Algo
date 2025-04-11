// LC - 705 - Easy - Design HashSet
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;
class HashSet{
    int MOD;
    vector<list<int>>buckets;
    int getHashIdx(int key){
        return key%MOD;
    }
    public:
    HashSet(){
        MOD=15000;
        buckets=vector<list<int>>(MOD,list<int>{});
    }
    void add(int key){
        int idx=getHashIdx(key);
        auto itr=find(buckets[idx].begin(),buckets[idx].end(),key);

        if(itr==buckets[idx].end()){
            buckets[idx].push_back(key);
        }
    }
    void remove(int key){
        int idx=getHashIdx(key);
        auto itr=find(buckets[idx].begin(),buckets[idx].end(),key);

        if(itr!=buckets[idx].end()){
            buckets[idx].remove(key);
        }
    }
    bool contains(int key){
        int idx=getHashIdx(key);
        auto itr=find(buckets[idx].begin(),buckets[idx].end(),key);

        if(itr!=buckets[idx].end()) return true;
        return false;
    }
};