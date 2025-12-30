// LC - 840 - Medium - Magic Squares In Grid
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Matrix{
    bool isMagicGrid(vector<vector<int>>&grid,int r,int c){
        unordered_set<int>st;
        
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int num=grid[r+i][c+j];
                
                if(num<1 || num>9 || st.count(num)){
                    return false;
                } else{
                    st.insert(num);
                }
            }
        }

        // check sum - Rows and columns
        int sum=grid[r][c]+grid[r][c+1]+grid[r][c+2];
        
        for(int i=0;i<3;i++){
            if(grid[r+i][c]+grid[r+i][c+1]+grid[r+i][c+2]!=sum){
                return false;
            }

            if(grid[r][c+i]+grid[r+1][c+i]+grid[r+2][c+i]!=sum){
                return false;
            }
        }
        // diagonal and anti-diagonal
        if(grid[r][c]+grid[r+1][c+1]+grid[r+2][c+2]!=sum){
            return false;
        }

        if(grid[r][c+2]+grid[r+1][c+1]+grid[r+2][c]!=sum){
            return false;
        }

        return true;
    }
    public:
    int numMagicSquaresInside(vector<vector<int>>&grid){
        int m=grid.size();
        int n=grid[0].size();

        int ans=0;

        for(int i=0;i<=m-3;i++){
            for(int j=0;j<=n-3;j++){
                if(isMagicGrid(grid,i,j)) ans++;
            }
        }

        return ans;
    }
};
int main(){
    // Output: 1
    vector<vector<int>>grid={{4,3,8,4},{9,5,1,9},{2,7,6,2}};
    // Output: 0
    vector<vector<int>>grid2={{8}};

    Matrix sol;
    cout<<sol.numMagicSquaresInside(grid)<<endl;
    cout<<sol.numMagicSquaresInside(grid2);
    return 0;
}