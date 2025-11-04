// GFG - Medium - Frog Jump
#include<iostream>
#include<vector>
using namespace std;
class DP{
    int n;
    vector<int>dp;
    int solve(vector<int>&height,int i){
        if(i>=n) return INT_MAX;
        
        if(i==n-1) return 0;
        
        if(dp[i]!=-1) return dp[i];
        
        int jumpOne=abs(height[i]-height[i+1])+solve(height,i+1);
        
        int jumpTwo=INT_MAX;
        if(i+2<n){
            jumpTwo=abs(height[i]-height[i+2])+solve(height,i+2);
        }
        
        return dp[i]=min(jumpOne,jumpTwo);
    }
    public:
    int minCost(vector<int>&height){
        n=height.size();
        
        dp.resize(n,-1);

        return solve(height,0);
    }
};
int main(){
    // Output: 20
    vector<int>heights={20,30,40,20};
    // Output: 30
    vector<int>heights2={30,20,50,10,40};

    DP sol;
    cout<<sol.minCost(heights)<<endl;
    cout<<sol.minCost(heights2);
    return 0;
}