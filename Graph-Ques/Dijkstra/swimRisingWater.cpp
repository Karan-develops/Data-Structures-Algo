// LC - 778 - HARD - Swim in Rising Water
// 2 Approaches
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// Approach 1 - Binary Search
// We need to find the maximum value in minimized path
class BinarySearch{
    int n;
    vector<vector<int>>directions{{0,1},{1,0},{0,-1},{-1,0}};
    bool isPossible(vector<vector<int>>&grid,vector<vector<bool>>&visited,int mid,int i,int j){
        if(i<0 || i>=n || j<0 || j>=n || visited[i][j] || grid[i][j]>mid){
            return false;
        }

        if(i==n-1 && j==n-1) return true;

        visited[i][j]=true;

        for(auto &dir:directions){
            int i_=i+dir[0];
            int j_=j+dir[1];

            if(isPossible(grid,visited,mid,i_,j_)){
                return true;
            }
        }
        return false;
    }
    public:
    int swimInWater(vector<vector<int>>&grid){
        n=grid.size();

        int l=0;
        int r=n*n-1;
        int ans=0;

        while(l<=r){
            int mid=l+(r-l)/2;
            vector<vector<bool>>visited(n,vector<bool>(n,false));

            if(isPossible(grid,visited,mid,0,0)){
                ans=mid;
                r=mid-1;
            } else{
                l=mid+1;
            }
        }
        return ans;
    }
};
class Dijkstra{
    // {time,{i,j}}
    typedef pair<int,pair<int,int>>P;
    vector<vector<int>>directions{{0,1},{1,0},{0,-1},{-1,0}};
    public:
    int swimInWater(vector<vector<int>>&grid){
        int n=grid.size();

        priority_queue<P,vector<P>,greater<P>>pq;
        vector<vector<int>>ans(n,vector<int>(n,INT_MAX));

        ans[0][0]=grid[0][0];
        pq.push({grid[0][0],{0,0}});

        while(!pq.empty()){
            int currTime=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();

            if(i==n-1 && j==n-1){
                return currTime;
            }

            if(currTime>ans[i][j]) continue;

            for(auto &dir:directions){
                int i_=i+dir[0];
                int j_=j+dir[1];

                if(i_>=0 && i_<n && j_>=0 && j_<n){
                    int nextTime=max(currTime,grid[i_][j_]);

                    if(nextTime<ans[i_][j_]){
                        pq.push({nextTime,{i_,j_}});
                        ans[i_][j_]=nextTime;
                    }
                }
            }
        }
        return -1;
    }
};
int main(){
    // Output: 3
    vector<vector<int>>grid={{0,2},{1,3}};
    // Output: 16
    vector<vector<int>>grid2={{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}};

    Dijkstra sol;
    cout<<sol.swimInWater(grid)<<endl;
    cout<<sol.swimInWater(grid2);
    return 0;
}