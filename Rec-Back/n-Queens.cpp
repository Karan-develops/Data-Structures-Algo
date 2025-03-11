#include<iostream>
#include<vector>
using namespace std;
class Solution{
    int N;
    bool isSafe(vector<string>&board,int row,int col){
        // Check Upward
        for(int i=row;i>=0;i--){
            if(board[i][col]=='Q') return false;
        }
        // Check Upward-left
        for(int i=row,j=col;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q') return false;
        }
        // Check Upward-right
        for(int i=row,j=col;i>=0 && j<N;i--,j++){
            if(board[i][j]=='Q') return false;
        }
        return true;
    }
    void solve(vector<string>&board,vector<vector<string>>&ans,int row){
        if(row==N){
            ans.push_back(board);
            return;
        }
        for(int col=0;col<N;col++){
            if(isSafe(board,row,col)){
                board[row][col]='Q';
                solve(board,ans,row+1);
                board[row][col]='.';
            }
        }
    }
    public:
    Solution(int n){
        this->N=n;
    }
    vector<vector<string>> nQueens(){
        if(N==0) return {};
        vector<vector<string>>ans;
        vector<string>board(N,string(N,'.'));
        solve(board,ans,0);
        return ans;
    }
};
int main(){
    Solution sol(4);
    vector<vector<string>>ans=sol.nQueens();
    for(auto &vec:ans){
        cout<<"[";
        for(auto &i:vec) cout<<i;
        cout<<"]";
    }
    return 0;
}