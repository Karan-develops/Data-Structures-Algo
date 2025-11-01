// LC - 1765 - Medium - Map of Highest Peak
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class BFS{
    typedef pair<int,int>P;
    vector<vector<int>>directions{{0,1},{0,-1},{-1,0},{1,0}};
    public:
    vector<vector<int>> highestPeak(vector<vector<int>>&isWater){
        int m=isWater.size();
        int n=isWater[0].size();
       
        vector<vector<int>>ans(m,vector<int>(n,-1));
        queue<P>q;
        
        // Mark all zeroes & store indices of 0 in queue
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]==1){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty()){
            int N=q.size();
            
            while(N--){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                
                for(auto &dir:directions){
                    int i_=i+dir[0];
                    int j_=j+dir[1];

                    if(i_>=0 && i_<m && j_>=0 && j_<n && ans[i_][j_]==-1){
                        ans[i_][j_]=ans[i][j]+1;
                        q.push({i_,j_});
                    }
                }
            }
        }
        
        return ans;
    }
};
int main(){
    // Output: [[1,0],[2,1]]
    vector<vector<int>>isWater={{0,1},{0,0}};
    // Output: [[1,1,0],[0,1,1],[1,2,2]]
    vector<vector<int>>isWater2={{0,0,1},{1,0,0},{0,0,0}};
    return 0;
}