// LC - 238 - Medium - Product of Array Except Self
#include<iostream>
#include<vector>
using namespace std;
vector<int> productExceptSelf(vector<int>&nums){
    int n=nums.size();
    vector<int>left(n-1,1);
    left.push_back(1);

    for(int i=0;i<n;i++){
        left[i]=left[i-1]*nums[i-1];
    }

    int right=1;
    for(int i=n-1;i>=0;i--){
        left[i]*=right;
        // Doing Multiplication From Right Side
        right*=nums[i];
    }
    return left;
}
int main(){
    // Output: [24,12,8,6]
    vector<int>nums={1,2,3,4};
    // Output: [0,0,9,0,0]
    vector<int>nums2={-1,1,0,-3,3};
    vector<int>ans=productExceptSelf(nums);
    for(int &i:ans) cout<<i<<" ";
    return 0;
}