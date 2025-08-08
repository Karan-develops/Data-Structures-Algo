// LC - 3363 - HARD - Find the Maximum Number of Fruits Collected
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class DP{
    int n;
    vector<vector<int>>dp;
    int child1Collect(vector<vector<int>>&fruits){
        int ans=0;

        // Will collect diagonal fruits bcoz (n-1) steps
        for(int i=0;i<n;i++){
            ans+=fruits[i][i];
        }
        return ans;
    }
    int child2Collect(vector<vector<int>>&fruits,int i,int j){
        if(i>=n || j<0 || j>=n){
            return 0;
        }

        // Can't cross diagonal -> (n-1) Steps
        if(i==j || i>j) return 0;

        // Reached End
        if(i==n-1 && j==n-1) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];

        int bottomLeft=fruits[i][j]+child2Collect(fruits,i+1,j-1);
        int bottomRight=fruits[i][j]+child2Collect(fruits,i+1,j+1);
        int bottom=fruits[i][j]+child2Collect(fruits,i+1,j);

        return dp[i][j]=max({bottomLeft,bottomRight,bottom});
    }
    int child3Collect(vector<vector<int>>&fruits,int i,int j){
        if(i>=n || j<0 || j>=n){
            return 0;
        }

        // Can't cross diagonal -> (n-1) Steps
        if(i==j || i<j) return 0;
        
        // Reached End
        if(i==n-1 && j==n-1) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int right=fruits[i][j]+child3Collect(fruits,i,j+1);
        int rightUp=fruits[i][j]+child3Collect(fruits,i-1,j+1);
        int rightDown=fruits[i][j]+child3Collect(fruits,i+1,j+1);

        return dp[i][j]=max({right,rightUp,rightDown});
    }
    public:
    int maxCollectedFruits(vector<vector<int>>&fruits){
        n=fruits.size();

        dp.resize(n+1,vector<int>(n+1,-1));

        int c1=child1Collect(fruits);
        int c2=child2Collect(fruits,0,n-1);
        int c3=child3Collect(fruits,n-1,0);

        return c1+c2+c3;
    }
};
int main(){
    // Output: 100
    vector<vector<int>>fruits={{1,2,3,4},{5,6,8,7},{9,10,11,12},{13,14,15,16}};
    // Output: 4
    vector<vector<int>>fruits2={{1,1},{1,1}};

    DP sol;
    cout<<sol.maxCollectedFruits(fruits)<<endl;
    cout<<sol.maxCollectedFruits(fruits2);
    return 0;
}