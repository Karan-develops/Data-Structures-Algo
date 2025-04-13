// LC - 2352 - Medium - Equal Row and Column Pairs
#include<iostream>
#include<vector>
#include<map>
using namespace std;
int equalPairs(vector<vector<int>>&grid){
    int n=grid.size();
    int ans=0;
    map<vector<int>,int>mp;
    for(auto &vec:grid){
        mp[vec]++;
    }
    for(int i=0;i<n;i++){
        vector<int>temp;
        for(int j=0;j<n;j++){
            temp.push_back(grid[j][i]);
        }
        if(mp[temp]) ans+=mp[temp];
    }
    return ans;
}
int main(){
    // Output: 1
    vector<vector<int>>grid={{3,2,1},{1,7,6},{2,7,7}};
    // Output: 3
    vector<vector<int>>grid2={{3,1,2,2},{1,4,4,5},{2,4,2,2},{2,4,2,2}};
    cout<<equalPairs(grid)<<endl;
    cout<<equalPairs(grid2);
    return 0;
}