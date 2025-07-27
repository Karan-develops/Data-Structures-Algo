// LC - 303 - Easy - Range Sum Query - Immutable
#include<iostream>
#include<vector>
using namespace std;
class Prefix{
public:
    vector<int>prefixSum;
    
    Prefix(vector<int>&nums){
        int n=nums.size();

        prefixSum.resize(n+1);
        prefixSum[0]=0;

        for(int i=1;i<=n;i++){
            prefixSum[i]=prefixSum[i-1]+nums[i-1];
        }
    }
    
    int sumRange(int left,int right){
        return prefixSum[right+1]-prefixSum[left];
    }
};
/*
Example 1:
Input:
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
Output:
[null, 1, -1, -3]
*/