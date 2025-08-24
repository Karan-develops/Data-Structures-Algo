// LC - 1493 - Medium - Longest Subarray of 1's After Deleting One Element
#include<iostream>
#include<vector>
using namespace std;
int longestSubarray(vector<int>&nums){
    int n=nums.size();

    int i=0,j=0;
    int zeroes=0;
    int ans=0;

    while(j<n){
        while(j<n && zeroes<=1){
            if(nums[j]==0) zeroes+=1;
            j++;
        }
        
        if(zeroes==0) zeroes=1;
        ans=max(ans,j-i-zeroes);

        while(i<j && zeroes!=1){
            if(nums[i]==0) zeroes-=1;
            i++;
        }
    }
    return ans;
}
int main(){
    // Output: 3
    vector<int>nums={1,1,0,1};
    // Output: 5
    vector<int>nums2={0,1,1,1,0,1,1,0,1};
    // Output: 2
    vector<int>nums3={1,1,1};
    cout<<longestSubarray(nums)<<endl;
    cout<<longestSubarray(nums2)<<endl;
    cout<<longestSubarray(nums3);
    return 0;
}