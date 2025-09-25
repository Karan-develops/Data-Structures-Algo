// LC - 1706 - Medium - Where Will the Ball Fall
#include<iostream>
#include<vector>
using namespace std;
vector<int> findBall(vector<vector<int>>&grid){
    int m=grid.size();
    int n=grid[0].size();

    vector<int>ans;

    for(int ball=0;ball<n;ball++){
        int i=0;
        int j=ball;
        bool reached=true;

        while(i<m && j<n){
            if(grid[i][j]==1){
                if(j==n-1 || grid[i][j+1]==-1){
                    reached=false;
                    break;
                }
                j++;
            } else{
                if(j==0 || grid[i][j-1]==1){
                    reached=false;
                    break;
                }
                j--;
            }
            i++;
        }

        if(reached) ans.push_back(j);
        else ans.push_back(-1);
    }

    return ans;
}
int main(){
    // Output: {1,-1,-1,-1,-1}
    vector<vector<int>>grid={{1,1,1,-1,-1},{1,1,1,-1,-1},{-1,-1,-1,1,1},{1,1,1,1,-1},{-1,-1,-1,-1,-1}};
    // Output: {-1}
    vector<vector<int>>grid2={{-1}};
    // Output: {0,1,2,3,4,-1}
    vector<vector<int>>grid3={{1,1,1,1,1,1},{-1,-1,-1,-1,-1,-1},{1,1,1,1,1,1},{-1,-1,-1,-1,-1,-1}};
    return 0;
}