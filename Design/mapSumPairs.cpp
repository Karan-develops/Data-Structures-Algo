// LC - 677 - Medium - Map Sum Pairs
// Also solved Using Trie
#include<iostream>
#include<unordered_map>
using namespace std;
class Design{
    public:
    unordered_map<string,int>mp;
    
    void insert(string key,int val){
        mp[key]=val;
    }

    int sum(string prefix){
        int sum=0;
        
        for(auto &it:mp){
            if(it.first.find(prefix)==0){
                sum+=it.second;
            }
        }
        return sum;
    }
};
/*
Example 1:
Input:
["MapSum", "insert", "sum", "insert", "sum"]
[[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
Output:
[null, null, 3, null, 5]
*/