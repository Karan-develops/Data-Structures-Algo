// GFG - Medium - 2D Submatrix Sum Queries
// 2 Approaches
#include<iostream>
#include<vector>
using namespace std;
// Approach 1 - Brute Force
vector<int> prefixSum2D(vector<vector<int>>&mat,vector<vector<int>>&queries){
    int m=mat.size();
    int n=mat[0].size();
    
    for(int i=0;i<m;i++){
        for(int j=1;j<n;j++){
            mat[i][j]+=mat[i][j-1];
        }
    }
    
    vector<int>ans;
    
    for(auto &vec:queries){
        int row1=vec[0];
        int row2=vec[2];
        int col1=vec[1];
        int col2=vec[3];
        
        int sum=0;
        for(int row=row1;row<=row2;row++){
            sum+=mat[row][col2]-(col1>0?mat[row][col1-1]:0);
        }
        
        ans.push_back(sum);
    }
    
    return ans;
}
// Approach 2 - Improved
vector<int> prefixSum2DOptimized(vector<vector<int>>&mat,vector<vector<int>>&queries){
    int m=mat.size();
    int n=mat[0].size();

    vector<vector<int>>prefix(m,vector<int>(n,0));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            prefix[i][j]=mat[i][j];
            
            if(i>0) prefix[i][j]+=prefix[i-1][j];
            if(j>0) prefix[i][j]+=prefix[i][j-1];
            if(i>0 && j>0) prefix[i][j]-=prefix[i-1][j-1];
        }
    }

    vector<int>ans;

    for(auto &vec:queries){
        int r1=vec[0];
        int c1=vec[1];
        int r2=vec[2];
        int c2=vec[3];

        int sum=prefix[r2][c2];
        
        if(r1>0) sum-=prefix[r1-1][c2];
        if(c1>0) sum-=prefix[r2][c1-1];
        if(r1>0 && c1>0) sum+=prefix[r1-1][c1-1];

        ans.push_back(sum);
    }

    return ans;
}
int main(){
    // Output: [5, 10]
    vector<vector<int>>mat={{1,2,3},{1,1,0},{4,2,2}},queries={{0,0,1,1},{1,0,2,2}};
    // Output: [4, 9, 3]
    vector<vector<int>>mat2={{1,1,1},{1,1,1},{1,1,1}},queries2={{1,1,2,2},{0,0,2,2},{0,2,2,2}};
    return 0;
}