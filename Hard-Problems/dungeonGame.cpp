// LC - 174 - HARD - Dungeon Game
// Topics --> Dynamic Programming
#include<iostream>
#include<vector>
#include<unordered_map>
#include<cstring>
using namespace std;
// Approach 1 - TLE - Binary Search on Ans
class BruteForceBinary{
    int m,n;
    bool canSurvive(int i,int j,int currHealth,vector<vector<int>>dungeon){
        if(i>=m || j>=n) return false;

        currHealth+=dungeon[i][j];
        if(currHealth<=0) return false;

        if(i==m-1 && j==n-1) return true;

        return canSurvive(i+1,j,currHealth,dungeon) || canSurvive(i,j+1,currHealth,dungeon);
    }
    public:
    int calculateMinimumHP(vector<vector<int>>&dungeon){
        m=dungeon.size(),n=dungeon[0].size();

        int l=1,r=4*1e7;
        int ans=r;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(canSurvive(0,0,mid,dungeon)){
                ans=mid;
                r=mid-1;
            } else{
                l=mid+1;
            }
        }
        return ans;
    }
};
// Approach 2 - TLE - Memoizing Approah 1
class BruteForceBinaryMemo{
    int m,n;
    unordered_map<string,int>dp;
    bool canSurvive(int i,int j,int currHealth,vector<vector<int>>dungeon){
        if(i>=m || j>=n) return false;

        currHealth+=dungeon[i][j];
        if(currHealth<=0) return false;

        if(i==m-1 && j==n-1) return true;

        string key=to_string(i)+"_"+to_string(j)+"_"+to_string(currHealth);
        if(dp.count(key)) return dp[key];

        return dp[key]=canSurvive(i+1,j,currHealth,dungeon) || canSurvive(i,j+1,currHealth,dungeon);
    }
    public:
    int calculateMinimumHP(vector<vector<int>>&dungeon){
        m=dungeon.size(),n=dungeon[0].size();

        int l=1,r=4*1e7;
        int ans=r;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(canSurvive(0,0,mid,dungeon)){
                ans=mid;
                r=mid-1;
            } else{
                l=mid+1;
            }
        }
        return ans;
    }
};
// Approach 3 - Recursion + Memo - ACCEPTED
class RecMemoTopDown{
    int m,n;
    int dp[201][201];
    int solve(int i,int j,vector<vector<int>>&dungeon){
        if(i==m || j==n) return 1e9;

        if(dp[i][j]!=-1) return dp[i][j];

        if(i==m-1 && j==n-1){
            if(dungeon[i][j]>0){
                return 1;
            } else{
                return abs(dungeon[i][j])+1;
            }
        }
        int down=solve(i+1,j,dungeon);
        int right=solve(i,j+1,dungeon);

        int ans=min(down,right)-dungeon[i][j];

        return dp[i][j]=ans>0?ans:1;
    }
    public:
    int calculateMinimumHP(vector<vector<int>>&dungeon){
        m=dungeon.size(),n=dungeon[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,dungeon);
    }
};
// Approach 4 - Bottom Up
class BottomUp{
    public:
    int calculateMinimumHP(vector<vector<int>>&dungeon){
        int m=dungeon.size(),n=dungeon[0].size();
        //NOTE : We will write bottom up by traversing from bottom right to top left because 
        // when we find t[i][j] we must be already aware of the health for down (t[i+1][j) and right (t[i][j+1])
      
        vector<vector<int>>dp(m,vector<int>(n,0));
        //t[i][j] = min health needed to reach (m-1, n-1) from (i,j)
        // Fill the rest of the DP table
        for(int i=m-1;i>=0;--i){
            for(int j=n-1;j>=0;--j){
                if(i==m-1 && j==n-1){
                    dp[i][j]=(dungeon[m-1][n-1]>0?1:abs(dungeon[m-1][n-1])+1);
                } else{
                    int down=(i+1>=m)?1e9:dp[i+1][j]; // Health needed if moving down
                    int right=(j+1>=n)?1e9:dp[i][j+1]; // Health needed if moving right
                    int res=min(down,right)-dungeon[i][j]; // Calculate the required health

                    // If the result is <= 0, we need at least 1 health
                    dp[i][j]=(res>0?res:1);
                }
            }
        }
        // The result is the minimum health required to start at the top-left corner
        return dp[0][0];
    }
};
int main(){
    // Output: 7
    vector<vector<int>>dungeon={{-2,-3,3},{-5,-10,1},{10,30,-5}};
    // Output: 1
    vector<vector<int>>dungeon2={{0}};
    return 0;
}