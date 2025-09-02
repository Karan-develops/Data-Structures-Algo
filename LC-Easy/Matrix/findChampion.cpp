// LC - 2923 - Easy - Find Champion I
// Topics -> Array, Matrix
#include<iostream>
#include<vector>
using namespace std;
int findChampion(vector<vector<int>>&grid){
    int n=grid.size();
    int max=0,ans=0;

    for(int i=0;i<n;i++){
        int currMax=0;

        for(int j=0;j<n;j++){
            if(grid[i][j]==1) currMax++;
        }
        
        if(currMax>max){
            max=currMax;
            ans=i;
        }
    }
    return ans;
}
int main(){
    // Output: 0
    vector<vector<int>>grid={{0,1},{0,0}};
    // Output: 1
    vector<vector<int>>grid2={{0,0,1},{1,0,1},{0,0,0}};
    cout<<findChampion(grid)<<endl;
    cout<<findChampion(grid2);
    return 0;
}