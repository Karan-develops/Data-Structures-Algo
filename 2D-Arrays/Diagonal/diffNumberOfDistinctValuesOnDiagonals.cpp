// LC - 2711 - Medium - Difference of Number of Distinct Values on Diagonals
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>&grid){
    int m=grid.size();
    int n=grid[0].size();

    vector<vector<int>>ans(m,vector<int>(n,0));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int x,y;
            unordered_set<int>st;

            // Left Above
            x=i-1,y=j-1;
            while(x>=0 && y>=0){
                st.insert(grid[x--][y--]);
            }
            // (int) bcoz st.size() return size_t type
            ans[i][j]=(int)st.size();
            
            st.clear();
            
            // Right Below
            x=i+1,y=j+1;
            while(x<m && y<n){
                st.insert(grid[x++][y++]);
            }
            
            // (int) bcoz st.size() return size_t type
            ans[i][j]=abs(ans[i][j]-(int)st.size());
        }
    }
    return ans;
}
int main(){
    // Output: Output: [[1,1,0],[1,0,1],[0,1,1]]
    vector<vector<int>>grid={{1,2,3},{3,1,5},{3,2,1}};
    // Output: Output: [[0]]
    vector<vector<int>>grid2={{1}};
    return 0;
}