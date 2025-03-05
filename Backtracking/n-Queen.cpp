#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
unordered_map<int,bool>rowCheck;
unordered_map<int,bool>upperLeftDiagonalCheck;
unordered_map<int,bool>bottomLeftDiagonalCheck;
void printBoard(vector<vector<char> >&board,int col){
    for(int i=0;i<col;i++){
        for(int j=0;j<col;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
// 2 Ways to write this function O(1) and O(n)
bool isSafe(vector<vector<char> >&board,int n,int row,int col){
    if(rowCheck[row]==true) return false;
    if(upperLeftDiagonalCheck[n-1+col-row]==true) return false;
    if(bottomLeftDiagonalCheck[row+col]==true) return false;
    return true;
    /*
    int i=row;
    int j=col;
    // check all previous horizontal columns
    while(j>=0){
        if(board[i][j]!='-'){
            return false;
        }
        j--;
    }
    // check the upper diagonal
    i=row;
    j=col;
    while(i>=0 && j>=0){
        if(board[i][j]!='-'){
            return false;
        }
        i--,j--;
    }
    // check the lower diagonal
    i=row;
    j=col;
    while(i<n && j>=0){
        if(board[i][j]!='-'){
            return false;
        }
        i++,j--;
    }
    return true;
    */
}
void solve(vector<vector<char> >&board,int n,int col){
    // Base case
    if(col>=n){
        printBoard(board,col);
        return;
    }
    // Solve 1 case rest recursion will solve
    for(int row=0;row<n;row++){
        if(isSafe(board,n,row,col)){
            // Place the Queen in cell
            board[row][col]='Q';
            rowCheck[row]=true;
            upperLeftDiagonalCheck[n-1+col-row]=true;
            bottomLeftDiagonalCheck[row+col]=true;
            // Recursive Call
            solve(board,n,col+1);
            // Backtracking
            board[row][col]='-';
            rowCheck[row]=false;
            upperLeftDiagonalCheck[n-1+col-row]=false;
            bottomLeftDiagonalCheck[row+col]=false;
        }
    }
}
int main(){
    int n=4;
    if(n<4){
        cout<<"No possible solution exists!";
        return 0;
    }
    vector<vector<char> >board(n,vector<char>(n,'-'));
    solve(board,n,0);
    return 0;
}