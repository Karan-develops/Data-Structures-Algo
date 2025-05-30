// LC - 3070 - Medium - Count Submatrices with Top-Left Element and Sum Less Than k
#include<iostream>
#include<vector>
using namespace std;
int countSubmatrices(vector<vector<int>>&grid,int k){
    int m=grid.size(),n=grid[0].size();
    int ans=0;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i>0) grid[i][j]+=grid[i-1][j];
            if(j>0) grid[i][j]+=grid[i][j-1];
            if(i>0 && j>0) grid[i][j]-=grid[i-1][j-1];

            if(grid[i][j]<=k) ans++;
            else break;
        }
    }
    return ans;
}
int main(){
    // Output: 4
    vector<vector<int>>grid={{7,6,3},{6,6,1}};
    int k=18;
    // Output: 6
    vector<vector<int>>grid2={{7,2,9},{1,5,0},{2,6,6}};
    int k2=20;
    cout<<countSubmatrices(grid,k)<<endl;
    cout<<countSubmatrices(grid2,k2);
    return 0;
}