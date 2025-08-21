// LC - 3643 - Easy - Flip Square Submatrix Vertically
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> reverseSubmatrix(vector<vector<int>>&grid,int x,int y,int k){
    int m=grid.size();
    int n=grid[0].size();

    int endRow=min(x+k,m);
    int endCol=min(y+k,n);
    
    for(int i=0;i<(endRow-x)/2;i++){
        int top=x+i;
        int bottom=endRow-1-i;

        for(int j=y;j<endCol;j++){
            swap(grid[top][j],grid[bottom][j]);
        }
    }
    return grid;
}
int main(){
    // Output: [[1,2,3,4],[13,14,15,8],[9,10,11,12],[5,6,7,16]]
    vector<vector<int>>grid={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int x=1,y=0,k=3;
    // Output: [[3,4,4,2],[2,3,2,3]]
    vector<vector<int>>grid2={{3,4,2,3},{2,3,4,2}};
    int x2=0,y2=2,k2=2;
    return 0;
}