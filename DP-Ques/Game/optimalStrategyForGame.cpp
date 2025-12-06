// GFG - Medium - Optimal Strategy For A Game
#include<iostream>
#include<vector>
using namespace std;
class DP{
    vector<vector<int>>dp;
    int solve(vector<int>&arr,int i,int j){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int pickLeft=arr[i]+min(solve(arr,i+2,j),solve(arr,i+1,j-1));
        int pickRight=arr[j]+min(solve(arr,i,j-2),solve(arr,i+1,j-1));

        return dp[i][j]=max(pickLeft,pickRight);
    }
    public:
    int maximumAmount(vector<int>&arr){
        int n=arr.size();
        
        dp.assign(n,vector<int>(n,-1));
        
        return solve(arr,0,n-1);
    }
};
int main(){
    // Output: 15
    vector<int>arr={5,3,7,10};
    // Output: 22
    vector<int>arr2={8,15,3,7};

    DP sol;
    cout<<sol.maximumAmount(arr)<<endl;
    cout<<sol.maximumAmount(arr2);
    return 0;
}