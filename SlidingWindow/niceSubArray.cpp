// LC - 2401 - Medium - Longest Nice Subarray
#include<iostream>
#include<vector>
using namespace std;
int longestNiceSubarray(vector<int>&nums){
    int n=nums.size();
    int i=0,j=0;
    int ans=1;
    int mask=0;
    // O(2*n)
    while(j<n){
        while((mask&nums[j])!=0){
            // XOR krne se wo element window (mask) se delete ho jaega
            mask^=nums[i];
            i++;
        }
        ans=max(ans,j-i+1);
        mask|=nums[j];
        j++;
    }
    return ans;
}
int main(){
    // OP - 3
    vector<int>nums1={1,3,8,48,10};
    // OP - 1
    vector<int>nums2={3,1,5,11,13};
    cout<<longestNiceSubarray(nums1)<<endl;
    cout<<longestNiceSubarray(nums2);
    return 0;
}