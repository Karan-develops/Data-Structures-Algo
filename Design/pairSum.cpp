// LC - 1865 - Medium - Finding Pairs With a Certain Sum
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class FindSumPairs{
    public:
    vector<int>vec1,vec2;
    unordered_map<int,int>mp;
    FindSumPairs(vector<int>&nums1,vector<int>&nums2){
        for(int &i:nums2) mp[i]++;
        vec1=nums1;
        vec2=nums2;
    }
    
    void add(int index,int val){
        mp[vec2[index]]--;
        vec2[index]+=val;
        mp[vec2[index]]++;
    }
    
    int count(int tot){
        int ans=0;
        for(int &i:vec1){
            if(mp.count(tot-i)){
                ans+=mp[tot-i];
            }
        }
        return ans;
    }
};