// LC - 1480 - Easy - Running Sum of 1d Array
#include<iostream>
#include<vector>
using namespace std;
vector<int> runningSum(vector<int>&nums){
    for(int i=1;i<nums.size();i++){
        nums[i]=nums[i]+nums[i-1];
    }
    return nums;
}
int main(){
    // Output: [1,3,6,10]
    vector<int>nums={1,2,3,4};
    // Output: [1,2,3,4,5]
    vector<int>nums2={1,1,1,1,1};
    // Output: [3,4,6,16,17]
    vector<int>nums3={3,1,2,10,1};
    return 0;
}