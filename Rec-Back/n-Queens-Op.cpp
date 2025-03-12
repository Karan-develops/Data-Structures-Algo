// Optimized Version
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution{
    int n;
    vector<vector<string>>ans;
    void solve(vector<string>&board,unordered_set<int>&cols,unordered_set<int>&diags,unordered_set<int>&antiDiags,int row){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int col=0;col<n;col++){
            // Formula
            int diagonal_id=row-col;
            int antiDiagonal_id=row+col;

            // Checking if the cell is safe or not
            if(cols.find(col)!=cols.end() || diags.find(diagonal_id)!=diags.end() || antiDiags.find(antiDiagonal_id)!=antiDiags.end()){
                continue;
            }

            cols.insert(col);
            diags.insert(diagonal_id);
            antiDiags.insert(antiDiagonal_id);
            board[row][col]='Q';

            solve(board,cols,diags,antiDiags,row+1);

            cols.erase(col);
            diags.erase(diagonal_id);
            antiDiags.erase(antiDiagonal_id);
            board[row][col]='.';
        }
    }
    public:
    Solution(int n){
        this->n=n;
    }
    vector<vector<string>> nQueens(){
        vector<string>board(n,string(n,'.'));
        int start_row=0;
        unordered_set<int>cols;
        unordered_set<int>diags;
        unordered_set<int>antiDiags;
        solve(board, cols, diags, antiDiags,start_row);
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