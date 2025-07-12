// GFG - Gold Mine Problem
#include<iostream>
#include<vector>
using namespace std;
class DP{
    int m,n;
    vector<vector<int>>dp;
    vector<vector<int>>directions{{0,1},{-1,1},{1,1}};
    int solve(vector<vector<int>>&mat,int i,int j){
        if(i>=m || i<0 || j>=n || j<0){
            return 0;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans=0;
        
        for(auto &dir:directions){
            int i_=i+dir[0];
            int j_=j+dir[1];
            
            ans=max(ans,solve(mat,i_,j_));
        }
        return dp[i][j]=ans+mat[i][j];
    }
    public:
    int maxGold(vector<vector<int>>&mat){
        m=mat.size(),n=mat[0].size();
        int ans=0;
        dp.assign(m,vector<int>(n,-1));
        
        for(int i=0;i<m;i++){
            ans=max(ans,solve(mat,i,0));
        }
        return ans;
    }
};
int main(){
    // Output: 12
    vector<vector<int>>mat={{1,3,3},{2,1,4},{0,6,4}};
    // Output: 16
    vector<vector<int>>mat2={{1,3,1,5},{2,2,4,1},{5,0,2,3},{0,6,1,2}};
    // Output: 14
    vector<vector<int>>mat3={{1,3,3},{2,1,4},{0,7,5}};

    DP sol;
    cout<<sol.maxGold(mat)<<endl;
    cout<<sol.maxGold(mat2)<<endl;
    cout<<sol.maxGold(mat3);
    return 0;
}