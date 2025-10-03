// LC - 407 - HARD - Trapping Rain Water II
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Heap{
    typedef pair<int,pair<int,int>>P;
    vector<vector<int>>directions={{0,-1},{0,1},{-1,0},{1,0}};
    public:
    int trapRainWater(vector<vector<int>>&heightMap){
        int m=heightMap.size();
        int n=heightMap[0].size();

        priority_queue<P,vector<P>,greater<>>boundaryCells;
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        
        for(int i=0;i<m;i++){
            for(int j:{0,n-1}){
                boundaryCells.push({heightMap[i][j],{i,j}});
                visited[i][j]=true;
            }
        }

        for(int j=0;j<n;j++){
            for(int i:{0,m-1}){
                boundaryCells.push({heightMap[i][j],{i,j}});
                visited[i][j]=true;
            }
        }
        
        int water=0;
        
        while(!boundaryCells.empty()){
            P p=boundaryCells.top();
            boundaryCells.pop();
            int h=p.first;
            int i=p.second.first;
            int j=p.second.second;
            
            for(auto &dir:directions){
                int i_=i+dir[0];
                int j_=j+dir[1];
                
                if(i_>=0 && i_<m && j_>=0 && j_<n && !visited[i_][j_]){
                    water+=max(h-heightMap[i_][j_],0);
                    boundaryCells.push({max(h,heightMap[i_][j_]),{i_,j_}});
                    visited[i_][j_]=true;
                }
            }
        }
        return water;
    }
};
int main(){
    // Output: 4
    vector<vector<int>>heightMap={{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}};
    // Output: 10
    vector<vector<int>>heightMap2={{3,3,3,3,3},{3,2,2,2,3},{3,2,1,2,3},{3,2,2,2,3},{3,3,3,3,3}};

    Heap sol;
    cout<<sol.trapRainWater(heightMap)<<endl;
    cout<<sol.trapRainWater(heightMap2);
    return 0;
}