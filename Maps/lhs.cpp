// LC - 594 - Easy - Longest Harmonious Subsequence
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int findLHS(vector<int>&nums){
    unordered_map<int,int>mp;

    int ans=0;

    for(int &i:nums) mp[i]++;

    for(int &num:nums){
        int minNum=num;
        int maxNum=num+1;

        if(mp.count(maxNum)){
            ans=max(ans,mp[minNum]+mp[maxNum]);
        }
    }
    return ans;
}
int main(){
    // Output: 5
    vector<int>nums={1,3,2,2,5,2,3,7};
    // Output: 2
    vector<int>nums2={1,2,3,4};
    // Output: 0
    vector<int>nums3={1,1,1,1};
    cout<<findLHS(nums)<<endl;
    cout<<findLHS(nums2)<<endl;
    cout<<findLHS(nums3);
    return 0;
}