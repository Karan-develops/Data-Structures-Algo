// LC - 2503 - HARD - Maximum Number of Points From Grid Queries
// Topics -> Array, Two Pointers, Breadth-First Search, Union Find, Sorting, Heap (Priority Queue), Matrix
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair<int,int>P;
vector<vector<int>>directions={{1,0},{0,1},{-1,0},{0,-1}};
// TLE
class BFS{
    int m,n;
    int bfs(vector<vector<int>>&grid,int queryVal){
        int points=0;
        queue<P>q;
        vector<vector<bool>>visited(m,vector<bool>(n,false));

        q.push({0,0});
        visited[0][0]=true;

        while(!q.empty()){
            int N=q.size();
            while(N--){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();

                if(grid[i][j]>queryVal) continue;

                points++;

                for(auto &dir:directions){
                    int i_=i+dir[0];
                    int j_=j+dir[1];

                    if(i_>=0 && i_<m && j_>=0 && j_<n && !visited[i_][j_] && grid[i_][j_]<queryVal){
                        q.push({i_,j_});
                        visited[i_][j_]=true;
                    }
                }
            }
        }
        return points;
    }
    public:
    vector<int> maxPoints(vector<vector<int>>&grid,vector<int>&queries){
        m=grid.size(),n=grid[0].size();
        int q=queries.size();
        vector<int>ans(q,0);
        
        for(int i=0;i<q;i++){
            ans[i]=bfs(grid,queries[i]);
        }
        return ans;
    }
};
// TLE
class DFS{
    int m,n;
    int dfs(vector<vector<int>>&grid,vector<vector<bool>>&visited,int qVal,int i,int j){
        if(i<0 || i>=m || j<0 || j>=n || visited[i][j] || grid[i][j]>=qVal){
            return 0;
        }
        visited[i][j]=true;
        int points=1;

        for(auto &dir:directions){
            int i_=i+dir[0];
            int j_=j+dir[1];

            points+=dfs(grid,visited,qVal,i_,j_);
        }
        return points;
    }
    public:
    vector<int> maxPoints(vector<vector<int>>&grid,vector<int>&queries){
        m=grid.size(),n=grid[0].size();
        int q=queries.size();
        vector<int>ans(q,0);

        for(int i=0;i<q;i++){
            vector<vector<bool>>visited(m,vector<bool>(n,false));
            ans[i]=dfs(grid,visited,queries[i],0,0);
        }
        return ans;
    }
};
// Optimized Using PQ
class PriorityQueue{
    public:
    vector<int> maxPoints(vector<vector<int>>&grid,vector<int>&queries){
        int m=grid.size(),n=grid[0].size();
        int q=queries.size();
        vector<int>ans(q,0);

        vector<P>sortedQueries;
        for(int i=0;i<q;i++){
            sortedQueries.push_back({queries[i],i});
        }
        sort(begin(sortedQueries),end(sortedQueries));

        int points=0;
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        priority_queue<vector<int>,vector<vector<int>>,greater<>>pq;

        pq.push({grid[0][0],0,0});
        visited[0][0]=true;

        for(int i=0;i<q;i++){
            int queryVal=sortedQueries[i].first;
            int idx=sortedQueries[i].second;

            while(!pq.empty() && pq.top()[0]<queryVal){
                int i=pq.top()[1];
                int j=pq.top()[2];
                pq.pop();

                points++;

                for(auto &dir:directions){
                    int i_=i+dir[0];
                    int j_=j+dir[1];

                    if(i_>=0 && i_<m && j_>=0 && j_<n && !visited[i_][j_]){
                        pq.push({grid[i_][j_],i_,j_});
                        visited[i_][j_]=true;
                    }
                }
            }
            ans[idx]=points;
        }
        return ans;
    }
};
int main(){
    // Output: [5,8,1]
    vector<vector<int>>grid={{1,2,3},{2,5,7},{3,5,1}};
    vector<int>queries={5,6,2};
    // Output: [0]
    vector<vector<int>>grid2={{5,2,1},{1,1,2}};
    vector<int>queries2={3};
    PriorityQueue obj;
    vector<int>ans1=obj.maxPoints(grid,queries);
    vector<int>ans2=obj.maxPoints(grid2,queries2);

    for(auto &i:ans1) cout<<i<<" ";
    cout<<endl;
    for(auto &i:ans2) cout<<i<<" ";
    return 0;
}