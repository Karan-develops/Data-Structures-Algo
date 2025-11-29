// GFG - Medium - Number of paths in a matrix with k coins
#include<iostream>
#include<vector>
using namespace std;
class DP{
    int m,n,K;
    vector<vector<vector<int>>>dp;
    int solve(vector<vector<int>>&mat,int collected,int i,int j){
        collected+=mat[i][j]; 
        
        if(i<0 || i>=m || j<0 || j>=n || collected>K){
            return 0;
        }
        
        if(i==m-1 && j==n-1 && collected==K){
            return 1;
        }
        
        if(dp[i][j][collected]!=-1) return dp[i][j][collected];
        
        
        int right=solve(mat,collected,i,j+1);
        int down=solve(mat,collected,i+1,j);
        
        return dp[i][j][collected]=right+down;
    }
    public:
    int numberOfPath(vector<vector<int>>&mat,int k){
        m=mat.size();
        n=mat[0].size();
        K=k;
        
        dp.assign(m,vector<vector<int>>(n,vector<int>(k+1,-1)));
        
        return solve(mat,0,0,0);
    }
};
int main(){
    // Output: 2
    int k=12;
    vector<vector<int>>mat={{1,2,3},{4,6,5},{3,2,1}};
    // Output: 0
    int k2=16;
    vector<vector<int>>mat2={{1,2,3},{4,6,5},{9,8,7}};

    DP sol;
    cout<<sol.numberOfPath(mat,k)<<endl;
    cout<<sol.numberOfPath(mat2,k2);
    return 0;
}