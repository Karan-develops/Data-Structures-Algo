// LC - 2206 - Easy - Divide Array Into Equal Pairs
// Topics - Array, Hash Table, Bit Manipulation, Counting
// 5 Approaches
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;
bool divideArrayWithMap(vector<int>&nums){
    unordered_map<int,int>mp;
    for(int &x:nums) mp[x]++;
    for(auto &it:mp){
        if(it.second%2!=0) return false;
    }
    return true;
}
bool divideArrayWithSet(vector<int>&nums){
    unordered_set<int>st;
    for(int &x:nums){
        if(st.count(x)) st.erase(x);
        else st.insert(x);
    }
    return st.empty();
}
bool divideArrayWithNegationVector(vector<int>&nums){
    //paird[i] = true , means ith element is present in pairs
    vector<bool>paired(501,true); 
    for(int &x:nums){
        paired[x]=!paired[x];
    }
    for(int i=0;i<501;i++){
        if(paired[i] == false) return false;
    }
    return true;
}
bool divideArrayWithSorting(vector<int>&nums){
    int n=nums.size();
    sort(begin(nums),end(nums));
    for(int i=1;i<n;i+=2){
        if(nums[i]!=nums[i-1]) return false;
    }
    return true;
}
bool divideArrayWithXOR(vector<int>&nums){
    int n=nums.size();
    sort(begin(nums),end(nums));
    for(int i=1;i<n;i+=2){
        if((nums[i]^nums[i-1])!=0) return false;
    }
    return true;
}
int main(){
    // OP - true
    vector<int>nums1={3,2,3,2,2,2};
    // OP - false
    vector<int>nums2={1,2,3,4};
    cout<<divideArrayWithMap(nums1)<<endl;
    cout<<divideArrayWithSet(nums2);
    return 0;
}