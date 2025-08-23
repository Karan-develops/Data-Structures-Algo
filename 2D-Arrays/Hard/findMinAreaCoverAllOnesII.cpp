// LC - 3197 - HARD - Find the Minimum Area to Cover All Ones II
#include<iostream>
#include<vector>
using namespace std;
class Matrix{
    int findMinArea(vector<vector<int>>&grid,int rowStart,int rowEnd,int colStart,int colEnd){
        int m=grid.size();
        int n=grid[0].size();

        int minRow=m,minCol=n,maxRow=-1,maxCol=-1;

        for(int i=rowStart;i<rowEnd;i++){
            for(int j=colStart;j<colEnd;j++){
                if(grid[i][j]==1){
                    if(i<minRow) minRow=i;
                    if(i>maxRow) maxRow=i;
                    if(j<minCol) minCol=j;
                    if(j>maxCol) maxCol=j;
                }
            }
        }

        int l=maxCol-minCol+1;
        int w=maxRow-minRow+1;

        return l*w;
    }
    vector<vector<int>> rotateGrid(vector<vector<int>>&grid){
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>>newRotatedGrid(n,vector<int>(m));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                newRotatedGrid[j][m-i-1]=grid[i][j];
            }
        }
        return newRotatedGrid;
    }
    int utility(vector<vector<int>>&grid){
        int m=grid.size();
        int n=grid[0].size();

        int ans=INT_MAX;

        for(int rowSplit=1;rowSplit<m;rowSplit++){
            for(int colSplit=1;colSplit<n;colSplit++){
                int top=findMinArea(grid,0,rowSplit,0,n);
                int bottomLeft=findMinArea(grid,rowSplit,m,0,colSplit);
                int bottomRight=findMinArea(grid,rowSplit,m,colSplit,n);

                ans=min(ans,(top+bottomLeft+bottomRight));

                int topLeft=findMinArea(grid,0,rowSplit,0,colSplit);
                int topRight=findMinArea(grid,0,rowSplit,colSplit,n);
                int bottom=findMinArea(grid,rowSplit,m,0,n);

                ans=min(ans,(topLeft+topRight+bottom));
            }
        }

        for(int row1Split=1;row1Split<m;row1Split++){
            for(int row2Split=row1Split+1;row2Split<m;row2Split++){
                int topRow=findMinArea(grid,0,row1Split,0,n);
                int middleRow=findMinArea(grid,row1Split,row2Split,0,n);
                int bottomRow=findMinArea(grid,row2Split,m,0,n);

                ans=min(ans,(topRow+middleRow+bottomRow));
            }
        }
        return ans;
    }
    public:
    int minimumSum(vector<vector<int>>&grid){
        int ans=utility(grid);

        vector<vector<int>>rotatedGrid=rotateGrid(grid);

        ans=min(ans,utility(rotatedGrid));

        return ans;
    }
};
int main(){
    // Output: 5
    vector<vector<int>>grid={{1,0,1},{1,1,1}};
    // Output: 5
    vector<vector<int>>grid2={{1,0,1,0},{0,1,0,1}};

    Matrix sol;
    cout<<sol.minimumSum(grid)<<endl;
    cout<<sol.minimumSum(grid2);
    return 0;
}