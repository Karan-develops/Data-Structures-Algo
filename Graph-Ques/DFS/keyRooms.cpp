// LC - 841 - Medium - Keys and Rooms
#include<iostream>
#include<vector>
using namespace std;
class DFS{
    void dfs(vector<vector<int>>&rooms,vector<bool>&visited,int node){
        visited[node]=true;
        for(auto &key:rooms[node]){
            if(!visited[key]){
                dfs(rooms,visited,key);
            }
        }
    }
    public:
    bool canVisitAllRooms(vector<vector<int>>&rooms){
        int n=rooms.size();
        vector<bool>visited(n,false);
        
        dfs(rooms,visited,0);

        for(const auto &i:visited){
            if(i==false) return false;
        }
        return true;
    }
};
int main(){
    // true
    vector<vector<int>>rooms={{1},{2},{3},{}};
    // false
    vector<vector<int>>rooms2={{1,3},{3,0,1},{2},{0}};
    DFS obj;
    cout<<obj.canVisitAllRooms(rooms)<<endl;
    cout<<obj.canVisitAllRooms(rooms2)<<endl;
    return 0;
}