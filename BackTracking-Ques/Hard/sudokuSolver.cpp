// LC - 37 - HARD - Sudoku Solver
// 2 Approaches
#include<iostream>
#include<vector>
using namespace std;
class BackTracking{
    bool isValid(vector<vector<char>>&board,char &ch,int i,int j){
        // Validate current row
        for(int col=0;col<9;col++){
            if(board[i][col]==ch) return false;
        }

        // Validate current col
        for(int row=0;row<9;row++){
            if(board[row][j]==ch) return false;
        }

        // Validate current box
        int start_i=(i/3)*3;
        int start_j=(j/3)*3;

        for(int k=0;k<3;k++){
            for(int l=0;l<3;l++){
                if(board[start_i+k][start_j+l]==ch) return false;
            }
        }
        return true;
    }
    // 1st
    bool solve1(vector<vector<char>>&board,int i,int j){
        // All rows checked
        if(i==9) return true;
        
        // current row over, go to next row starting from 0th column
        if(j==9) return solve1(board,i+1,0);
        
        // if it's filled go for next column
        if(board[i][j]!='.') return solve1(board,i,j+1);
        
        // else try putting '1' to '9' and see if you find the result in any
        for(char ch='1';ch<='9';ch++){
            if(isValid(board,ch,i,j)){
                board[i][j]=ch;

                if(solve1(board,i,j+1)) return true;

                board[i][j]='.';
            }
        }
        return false;
    }
    // 2nd
    bool solve(vector<vector<char>>&board){
        // O(9)
        for(int i=0;i<9;i++){
            // O(9)
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char d='1';d<='9';d++){ 
                        if(isValid(board,d,i,j)){
                            board[i][j]=d;

                            if(solve(board)==true){
                                return true;
                            }
                            
                            board[i][j] = '.';
                        }

                    }
                    return false;
                }
            }
        }
        return true;
    }
    public:
    void solveSudoku(vector<vector<char>>&board){
        solve(board);
    }
};
int main(){
    // Output: [['5','3','4','6','7','8','9','1','2'],['6','7','2','1','9','5','3','4','8'],['1','9','8','3','4','2','5','6','7'],['8','5','9','7','6','1','4','2','3'],['4','2','6','8','5','3','7','9','1'],['7','1','3','9','2','4','8','5','6'],['9','6','1','5','3','7','2','8','4'],['2','8','7','4','1','9','6','3','5'],['3','4','5','2','8','6','1','7','9']]
    vector<vector<char>>board={{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};

    BackTracking sol;
    sol.solveSudoku(board);
    return 0;
}