// LC - 1991 - Easy - Find the Middle Index in Array
#include<iostream>
#include<vector>
using namespace std;
int findMiddleIndex(vector<int>& nums) {
    int n=nums.size();
    int ans=0;

    int totalSum=0;
    for(int &i:nums) totalSum+=i;

    int leftSum=0;
    for(int i=0;i<n;i++){
        int rightSum=totalSum-leftSum-nums[i];
        if(leftSum==rightSum) return i;
        leftSum+=nums[i];
    }
    return -1;
}
int main(){
    // Output: 3
    vector<int>nums={2,3,-1,8,4};
    // Output: 2
    vector<int>nums2={1,-1,4};
    // Output: -1
    vector<int>nums3={2,5};
    cout<<findMiddleIndex(nums)<<endl;
    cout<<findMiddleIndex(nums2)<<endl;
    cout<<findMiddleIndex(nums3);
    return 0;
}