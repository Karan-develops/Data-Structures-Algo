// LC - 2639 - Easy - Find the Width of Columns of a Grid
#include<iostream>
#include<vector>
using namespace std;
vector<int> findColumnWidth(vector<vector<int>>& grid) {
    int m=grid.size(),n=grid[0].size();
    vector<int>ans(n,0);

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int curr=to_string(grid[i][j]).size();
            ans[j]=max(ans[j],curr);
        }
    }
    return ans;
}
int main(){
    // Output: [3]
    vector<vector<int>>grid={{1},{22},{333}};
    // Output: [3,1,2]
    vector<vector<int>>grid2={{-15,1,3},{15,7,12},{5,6,-2}};
    return 0;
}