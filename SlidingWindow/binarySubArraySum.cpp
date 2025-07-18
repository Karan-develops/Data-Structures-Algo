// LC - 930 - Medium - Binary Subarrays With Sum
// 2 Approaches
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
// Approach 1 - Sliding Window
int slidingWindow(vector<int>&nums,int goal){
    int n=nums.size();

    int i=0,j=0;
    int ans=0,sum=0;
    int zeroes=0;

    while(j<n){
        sum+=nums[j];

        while(i<j && (nums[i]==0 || sum>goal)){
            if(nums[i]==0) zeroes++;
            else zeroes=0;

            sum-=nums[i];
            i++;
        }

        if(sum==goal) ans+=(1+zeroes);

        j++;
    }

    return ans;
}
// Approach 2  - Prefix-Sum Map
int prefixSumMap(vector<int>&nums,int goal){
    int n=nums.size();

    unordered_map<int,int>mp;
    mp[0]++;

    int ans=0;
    int prefixSum=0;

    for(int &i:nums){
        prefixSum+=i;

        if(mp.count(prefixSum-goal)){
            ans+=mp[prefixSum-goal];
        }
        mp[prefixSum]++;
    }
    return ans;
}
int main(){
    // Output: 4
    vector<int>nums={1,0,1,0,1};
    int goal=2;
    // Output: 15
    vector<int>nums2={0,0,0,0,0};
    int goal2=0;
    cout<<slidingWindow(nums,goal)<<endl;
    cout<<slidingWindow(nums2,goal2);
    return 0;
}