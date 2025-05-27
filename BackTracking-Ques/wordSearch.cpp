// LC - 79 - Medium - Word Search
#include<iostream>
#include<vector>
using namespace std;
class BackTracking{
    int m,n;
    vector<vector<int>>directions{{-1,0},{1,0},{0,-1},{0,1}};
    bool solve(vector<vector<char>>&board,string &word,int i,int j,int idx){
        if(idx>=word.length()) return true;

        if(i<0 || i>=m || j<0 || j>=n || board[i][j]!=word[idx] || board[i][j]=='$'){
            return false;
        }

        char temp=board[i][j];
        board[i][j]='$';

        for(auto &dir:directions){
            int i_=i+dir[0];
            int j_=j+dir[1];

            if(solve(board,word,i_,j_,idx+1)) return true;
        }

        board[i][j]=temp;
        return false;
    }
    public:
    bool exist(vector<vector<char>>&board,string word){
        m=board.size(),n=board[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(word[0]==board[i][j] && solve(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }
};
int main(){
    // Output: true
    vector<vector<char>>board={{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word="ABCCED";
    // Output: true
    vector<vector<char>>board2={{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word2="SEE";
    // Output: false
    vector<vector<char>>board3={{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word3="ABCB";

    BackTracking sol;
    cout<<sol.exist(board,word)<<endl;
    cout<<sol.exist(board2,word2)<<endl;
    cout<<sol.exist(board3,word3);
    return 0;
}