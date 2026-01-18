// LC - 1895 - Medium - Largest Magic Square
#include<iostream>
#include<vector>
using namespace std;
int largestMagicSquare(vector<vector<int>>&grid){
    int rows=grid.size();
    int cols=grid[0].size();

    // Row wise Prefix Sum
    vector<vector<int>>rowCumsum(rows,vector<int>(cols));
    for(int i=0;i<rows;i++){
        rowCumsum[i][0]=grid[i][0];
        for(int j=1;j<cols;j++){
            rowCumsum[i][j]=rowCumsum[i][j-1]+grid[i][j];
        }
    }

    // Column wise Prefix Sum
    vector<vector<int>>colCumsum(rows,vector<int>(cols));
    for(int j=0;j<cols;j++){
        colCumsum[0][j]=grid[0][j];
        for(int i=1;i<rows;i++){
            colCumsum[i][j]=colCumsum[i-1][j]+grid[i][j];
        }
    }

    for(int side=min(rows,cols);side>=2;side--){
        for(int i=0;i+side-1<rows;i++){
            for(int j=0;j+side-1<cols;j++){
                int targetSum=rowCumsum[i][j+side-1]-(j>0?rowCumsum[i][j-1]:0);

                bool allSame=true;

                for(int r=i+1;r<i+side;r++){
                    int rowSum=rowCumsum[r][j+side-1]-(j>0?rowCumsum[r][j-1]:0);
                    if(rowSum!=targetSum){
                        allSame=false;
                        break;
                    }
                }
                
                if(!allSame) continue;

                // Check columns
                for(int c=j;c<j+side;c++){
                    int colSum=colCumsum[i+side-1][c]-(i>0?colCumsum[i-1][c]:0);
                    if(colSum!=targetSum){
                        allSame=false;
                        break;
                    }
                }
                
                if(!allSame) continue;

                // Check diagonals
                int diag=0;
                int antiDiag=0;
                for(int k=0;k<side;k++){
                    diag+=grid[i+k][j+k];
                    antiDiag+=grid[i+k][j+side-1-k];
                }

                if(diag==targetSum && antiDiag==targetSum){
                    return side;
                }
            }
        }
    }

    return 1;
}
int main(){
    // Output: 3
    vector<vector<int>>grid={{7,1,4,5,6},{2,5,1,6,4},{1,5,4,3,2},{1,2,7,3,4}};
    // Output: 2
    vector<vector<int>>grid2={{5,1,3,1},{9,3,3,1},{1,3,3,8}};
    cout<<largestMagicSquare(grid)<<endl;
    cout<<largestMagicSquare(grid2);
    return 0;
}