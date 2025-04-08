// LC - 380 - Medium - Insert Delete GetRandom O(1)
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class RandomizedSet{
    vector<int>vec;
    unordered_map<int,int>mp;
    public:
    bool insert(int val){
        if(mp.count(val)) return false;
        vec.push_back(val);
        mp[val]=vec.size()-1;
        return true;      
    }
    bool remove(int val){
        if(!mp.count(val)) return false;

        int temp=vec.back();
        int idx=mp[val];

        mp[temp]=idx;
        swap(vec[idx],vec.back());

        vec.pop_back();
        mp.erase(val);
        return true;
    }
    int getRandom(){
        int idx=rand()%vec.size();
        return vec[idx];
    }
};