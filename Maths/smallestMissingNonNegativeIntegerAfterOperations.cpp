// LC - 2598 - Medium - Smallest Missing Non-negative Integer After Operations
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int findSmallestInteger(vector<int>&nums,int value){
    unordered_map<int,int>mp;

    for(int &i:nums){
        int rem=((i%value)+value)%value;

        mp[rem]++;
    }

    int ans=0;
    while(mp[(ans%value)]>0){
        mp[(ans%value)]--;
        ans++;
    }

    return ans;
}
int main(){
    // Output: 4
    vector<int>nums={1,-10,7,13,6,8};
    int value=5;
    // Output: 2
    vector<int>nums2={1,-10,7,13,6,8};
    int value2=7;
    cout<<findSmallestInteger(nums,value)<<endl;
    cout<<findSmallestInteger(nums2,value2);
    return 0;
}