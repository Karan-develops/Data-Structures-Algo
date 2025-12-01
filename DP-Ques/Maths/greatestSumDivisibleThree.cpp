// LC - 1262 - Medium - Greatest Sum Divisible by Three
#include<iostream>
#include<vector>
using namespace std;
class MathsDP{
    int n;
    vector<vector<int>>dp;
    int solve(vector<int>&nums,int rem,int i){
        if(i>=n){
            return (rem==0)?0:INT_MIN;
        }

        if(dp[i][rem]!=-1) return dp[i][rem];

        // Pick the current number
        int take=nums[i]+solve(nums,(rem+nums[i])%3,i+1);

        // Skip the current number
        int skip=solve(nums,rem,i+1);

        return dp[i][rem]=max(take,skip);
    }
    public:
    int maxSumDivThree(vector<int>&nums){
        n=nums.size();
        dp.assign(n,vector<int>(3,-1));

        return solve(nums,0,0);
    }  
};
int main(){
    // Output: 18
    vector<int>nums={3,6,5,1,8};
    // Output: 0
    vector<int>nums2={4};
    // Output: 12
    vector<int>nums3={1,2,3,4,4};

    MathsDP sol;
    cout<<sol.maxSumDivThree(nums)<<endl;
    cout<<sol.maxSumDivThree(nums2)<<endl;
    cout<<sol.maxSumDivThree(nums3);
    return 0;
}