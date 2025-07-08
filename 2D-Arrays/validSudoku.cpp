// LC - 36 - Medium - Valid Sudoku
// 2 Approaches - Check Everything - Make Strings
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Sudoku{
    bool checkBoxes(vector<vector<char>>&board,int sr,int er,int sc,int ec){
        unordered_set<char>st;
        for(int i=sr;i<=er;i++){
            for(int j=sc;j<=ec;j++){
                char ch=board[i][j];
                if(ch=='.') continue;
                if(st.count(ch)) return false;
                st.insert(ch);
            }
        }
        return true;
    }
    public:
    bool isValidSudoku(vector<vector<char>>&board){
        // Validating Rows
        for(int i=0;i<9;i++){
            unordered_set<char>st;
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                if(st.count(board[i][j])) return false;
                st.insert(board[i][j]);
            }
        }
        // Validating Cols
        for(int j=0;j<9;j++){
            unordered_set<char>st;
            for(int i=0;i<9;i++){
                if(board[i][j]=='.') continue;
                if(st.count(board[i][j])) return false;
                st.insert(board[i][j]);
            }
        }
        // Validating each 3X3 Boxes
         for(int sr=0;sr<9;sr+=3){
            int er=sr+2;
            for(int sc=0;sc<9;sc+=3){
                int ec=sc+2;
                if(!checkBoxes(board, sr, er, sc, ec)){
                    return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku2(vector<vector<char>>&board){
        unordered_set<string>st;
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                
                string row=string(1,board[i][j])+"_row_"+to_string(i);
                string col=string(1,board[i][j])+"_col_"+to_string(j);
                string box=string(1,board[i][j])+"_box_"+to_string(i/3)+"_"+to_string(j/3);
                if(st.count(row) || st.count(col) || st.count(box)) return false;
                st.insert(row);
                st.insert(col);
                st.insert(box);
            }
        }
        return true;
    }
};
int main(){
    // Output: true
    vector<vector<char>>board= 
    {{'5','3','.','.','7','.','.','.','.'}
    ,{'6','.','.','1','9','5','.','.','.'}
    ,{'.','9','8','.','.','.','.','6','.'}
    ,{'8','.','.','.','6','.','.','.','3'}
    ,{'4','.','.','8','.','3','.','.','1'}
    ,{'7','.','.','.','2','.','.','.','6'}
    ,{'.','6','.','.','.','.','2','8','.'}
    ,{'.','.','.','4','1','9','.','.','5'}
    ,{'.','.','.','.','8','.','.','7','9'}};
    // Output: false
    vector<vector<char>>board2= 
    {{'8','3','.','.','7','.','.','.','.'}
    ,{'6','.','.','1','9','5','.','.','.'}
    ,{'.','9','8','.','.','.','.','6','.'}
    ,{'8','.','.','.','6','.','.','.','3'}
    ,{'4','.','.','8','.','3','.','.','1'}
    ,{'7','.','.','.','2','.','.','.','6'}
    ,{'.','6','.','.','.','.','2','8','.'}
    ,{'.','.','.','4','1','9','.','.','5'}
    ,{'.','.','.','.','8','.','.','7','9'}};

    Sudoku sol;
    cout<<sol.isValidSudoku(board)<<endl;
    cout<<sol.isValidSudoku(board2);
    return 0;
}