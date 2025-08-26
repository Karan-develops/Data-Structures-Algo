// LC - 3446 - Medium - Sort Matrix by Diagonals
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
vector<vector<int>> sortMatrix(vector<vector<int>>&grid){
    int n=grid.size();

    unordered_map<int,vector<int>>mp;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mp[i-j].push_back(grid[i][j]);
        }
    }

    for(auto &it:mp){
        if(it.first>=0){
            sort(begin(it.second),end(it.second),greater<>());
        } else{
            sort(begin(it.second),end(it.second));
        }
    }

    // Put in reverse order bcoz they are sorted
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            grid[i][j]=mp[i-j].back();

            mp[i-j].pop_back();
        }
    }
    return grid;
}
int main(){
    // Output: [[8,2,3],[9,6,7],[4,5,1]]
    vector<vector<int>>grid={{1,7,3},{9,8,2},{4,5,6}};
    // Output: [[2,1],[1,0]]
    vector<vector<int>>grid2={{0,1},{1,2}};
    return 0;
}