// LC - 1458 - HARD - Max Dot Product of Two Subsequences
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class DP{
    int m,n;
    int dp[501][501];
    int solve(vector<int>&nums1,vector<int>&nums2,int i,int j){
        if(i==m || j==n) return -100000000;
        
        if(dp[i][j]!=-1e9) return dp[i][j];
        
        int val=nums1[i]*nums2[j];
        
        int take_i_j=solve(nums1,nums2,i+1,j+1)+val;
        
        int take_i=solve(nums1,nums2,i,j+1);
        int take_j=solve(nums1,nums2,i+1,j);
        
        return dp[i][j]=max({val,take_i_j,take_i,take_j});
    }
    public:
    int maxDotProduct(vector<int>&nums1,vector<int>&nums2){
        m=nums1.size();
        n=nums2.size();
        
        for(int i=0;i<501;i++){
            for(int j=0;j<501;j++){
                dp[i][j]=-1e9;
            }
        }
        
        return solve(nums1,nums2,0,0);
    }
};
int main(){
    // Output: 18
    vector<int>nums1={2,1,-2,5},nums2={3,0,-6};
    // Output: 21
    vector<int>nums3={3,-2},nums4={2,-6,7};
    // Output: -1
    vector<int>nums5={-1,-1},nums6={1,1};

    DP sol;
    cout<<sol.maxDotProduct(nums1,nums2)<<endl;
    cout<<sol.maxDotProduct(nums3,nums4)<<endl;
    cout<<sol.maxDotProduct(nums5,nums6);
    return 0;
}