// LC - 1351 - Easy - Count Negative Numbers in a Sorted Matrix
#include<iostream>
#include<vector>
using namespace std;
int countNegatives(vector<vector<int>>&grid){
    int m=grid.size();
    int n=grid[0].size();

    int ans=0;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]<0) ans++;
        }
    }

    return ans;
}
int main(){
    // Output: 8
    vector<vector<int>>grid={{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}};
    // Output: 0
    vector<vector<int>>grid2={{3,2},{1,0}};
    cout<<countNegatives(grid)<<endl;
    cout<<countNegatives(grid2);
    return 0;
}