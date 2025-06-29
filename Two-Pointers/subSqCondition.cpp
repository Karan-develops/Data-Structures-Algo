// LC - 1498 - Medium - Number of Subsequences That Satisfy the Given Sum Condition
// 2 Approaches
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
const int MOD=1e9+7;
// Approach 1 - Simple Using Pow
int numSubseq(vector<int>&nums,int target){
    int n=nums.size();

    sort(begin(nums),end(nums));

    int l=0,r=n-1;
    int ans=0;

    while(l<=r){
        if(nums[l]+nums[r]<=target){
            ans+=pow(2,r-l);
            l++;
        } else{
            r--;
        }
    }
    return ans;
}
// Approach 2 - Precomputing Powers
int numSubseq(vector<int>&nums,int target){
    int n=nums.size();

    sort(begin(nums),end(nums));

    // PreCompute Powers
    vector<int>powers(n);
    powers[0]=1;
    for(int i=1;i<n;i++){
        powers[i]=(powers[i-1]*2)%MOD;
    }

    int l=0,r=n-1;
    int ans=0;

    while(l<=r){
        if(nums[l]+nums[r]<=target){
            ans=(ans+powers[r-l])%MOD;
            l++;
        } else{
            r--;
        }
    }
    return ans;
}