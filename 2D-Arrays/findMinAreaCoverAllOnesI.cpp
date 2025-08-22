// LC - 3195 - Medium - Find the Minimum Area to Cover All Ones I
#include<iostream>
#include<vector>
using namespace std;
int minimumArea(vector<vector<int>>&grid){
    int m=grid.size();
    int n=grid[0].size();

    int startRow=INT_MAX,startCol=INT_MAX,endRow=INT_MIN,endCol=INT_MIN;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                if(i<startRow) startRow=i;
                if(i>endRow) endRow=i;
                if(j<startCol) startCol=j;
                if(j>endCol) endCol=j;
            }
        }
    }

    int l=endCol-startCol+1;
    int w=endRow-startRow+1;

    return l*w;
}
int main(){
    // Output: 6
    vector<vector<int>>grid={{0,1,0},{1,0,1}};
    // Output: 1
    vector<vector<int>>grid2={{1,0},{0,0}};
    cout<<minimumArea(grid)<<endl;
    cout<<minimumArea(grid2);
    return 0;
}