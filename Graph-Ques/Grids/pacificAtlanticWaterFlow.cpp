// LC - 417 - Medium - Pacific Atlantic Water Flow
// 2 Approaches
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// Approach 1 - Brute Force - TLE
class BruteForce{
    int m,n;
    typedef pair<int,int>P;
    vector<vector<int>>directions{{0,1},{1,0},{0,-1},{-1,0}};
    bool reached(vector<vector<int>>&heights,int i,int j){
        queue<P>q;
        vector<vector<bool>>visited(m,vector<bool>(n,false));

        q.push({i,j});
        visited[i][j]=true;
        pair<bool,bool> reached={false,false};

        while(!q.empty()){
            int i_=q.front().first;
            int j_=q.front().second;
            q.pop();

            if(i_==0 || j_==0) reached.first=true;
            if(i_==m-1 || j_==n-1) reached.second=true;

            for(auto &dir:directions){
                int newI=i_+dir[0];
                int newJ=j_+dir[1];

                if(newI>=0 && newI<m && newJ>=0 && newJ<n && !visited[newI][newJ] 
                   && heights[i_][j_]>=heights[newI][newJ]){
                    q.push({newI,newJ});
                    visited[newI][newJ]=true;
                }
            }
        }

        if(reached.first && reached.second) return true;
        return false;
    }
    public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>&heights){
        m=heights.size();
        n=heights[0].size();

        vector<vector<int>>ans;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(reached(heights,i,j)){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
// Approach 2 - Better
class GridGraph{
    int m,n;
    vector<vector<int>>directions{{0,1},{1,0},{0,-1},{-1,0}};
    void dfs(vector<vector<int>>&heights,int prevCell,int i,int j,vector<vector<bool>>&visited){
        if(i<0 || i>=m || j<0 || j>=n || visited[i][j]){
            return;
        }

        if(heights[i][j]<prevCell){
            return;
        }

        visited[i][j]=true;
        
        for(auto &dir:directions){
            int i_=i+dir[0];
            int j_=j+dir[1];

            dfs(heights,heights[i][j],i_,j_,visited);
        }
    }
    public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>&heights){
        m=heights.size();
        n=heights[0].size();

        vector<vector<int>>ans;

        vector<vector<bool>>pacificVisited(m,vector<bool>(n,false));
        vector<vector<bool>>atlanticVisited(m,vector<bool>(n,false));

        for(int i=0;i<m;i++){
            dfs(heights,INT_MIN,i,0,pacificVisited);
            dfs(heights,INT_MIN,i,n-1,atlanticVisited);
        }
        
        for(int j=0;j<n;j++){
            dfs(heights,INT_MIN,0,j,pacificVisited);
            dfs(heights,INT_MIN,m-1,j,atlanticVisited);
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacificVisited[i][j] && atlanticVisited[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
int main(){
    // Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
    vector<vector<int>>heights={{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    // Output: [[0,0]]
    vector<vector<int>>heights2={{1}};
    return 0;
}