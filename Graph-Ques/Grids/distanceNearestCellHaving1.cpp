// LC - 542 - Medium - 01 Matrix
// GFG - Medium - Distance of nearest cell having 1
/*
In Leetcode we hv to find 0's
In GFG we hv to find 1's
*/
// 2 Approaches
#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
// Approach 1 - Brute Force - TLE
class BruteForce{
    int m,n;
    typedef pair<int,int>P;
    vector<vector<int>>directions{{0,1},{1,0},{0,-1},{-1,0}};
    int solve(vector<vector<int>>&mat,int x,int y){
        queue<P>q;
        set<P>visited;
        
        q.push({x,y});
        visited.insert({x,y});
        
        int cost=0;
        
        auto check=[&](int i,int j){
            return (i>=0 && i<m && j>=0 && j<n);  
        };
        
        while(!q.empty()){
            int N=q.size();
            
            while(N--){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                
                if(mat[i][j]==0) return cost;
                
                for(auto &dir:directions){
                    int i_=i+dir[0];
                    int j_=j+dir[1];
                    
                    if(!visited.count({i_,j_}) && check(i_,j_)){
                        visited.insert({i_,j_});
                        q.push({i_,j_});
                    }
                }
            }
            cost++;
        }
        
        return 0;
    }
    public:
     vector<vector<int>> updateMatrix(vector<vector<int>>&mat){
        m=mat.size();
        n=mat[0].size();
        
        vector<vector<int>>ans(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    ans[i][j]=solve(mat,i,j);
                }
            }
        }
        
        return ans;
    }
};
// Approach 2 - Mutli-Source BFS - ACCEPTED
class BFS{
    typedef pair<int,int>P;
    vector<vector<int>>directions{{0,1},{1,0},{0,-1},{-1,0}};
    public:
    vector<vector<int>> updateMatrix(vector<vector<int>>&mat){
        int m=mat.size();
        int n=mat[0].size();
        
        vector<vector<int>>ans(m,vector<int>(n,-1));
        queue<P>q;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        
        auto check=[&](int i,int j){
            return (i>=0 && i<m && j>=0 && j<n);  
        };

        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            
            for(auto &dir:directions){
                int i_=i+dir[0];
                int j_=j+dir[1];
                
                if(check(i_,j_) && ans[i_][j_]==-1){
                    q.push({i_,j_});
                    ans[i_][j_]=1+ans[i][j];
                }
            }
        }

        return ans;
    }
};
int main(){
    // Output: [[0,0,0],[0,1,0],[0,0,0]]
    vector<vector<int>>mat={{0,0,0},{0,1,0},{0,0,0}};
    // Output: [[0,0,0],[0,1,0],[1,2,1]]
    vector<vector<int>>mat2={{0,0,0},{0,1,0},{1,1,1}};
    return 0;
}