// LC - 909
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
pair<int,int> getCoordinates(int step,int n){
    // Bcoz matrix is starting from bottom
    int row=n-1-(step-1)/n;
    int col=(step-1)%n;
    if(row%2==0 && n%2==0 || row%2!=1 && n%2!=1){
        col=n-1-col;
    }
    return make_pair(row,col);
}
int snakesAndLadders(vector<vector<int>>&board){
    int n=board.size();
    int steps=0;
    vector<vector<bool>>visited(n,vector<bool>(n,false));
    queue<int>q;
    // Pushing Position 1
    q.push(1);
    visited[n-1][0]=true;
    while(!q.empty()){
        int N=q.size();
        while(N--){
            int currPosition=q.front();
            q.pop();

            // Agar game complete ho gyi toh return krdo ans
            if(currPosition==n*n) return steps;

            // Dice roll -> (1,6) -> jaha pe abhi khde ho
            for(int k=1;k<=6;k++){
                int nextPosition=k+currPosition;

                // Agar board se bahar ja rhe ho
                if(nextPosition>n*n) break;

                // Next Step ke x,y coordinates nikalo
                pair<int,int> P=getCoordinates(nextPosition,n);
                int r=P.first;
                int c=P.second;

                if(visited[r][c]==true) continue;
                visited[r][c]=true;

                if(board[r][c]==-1) q.push(nextPosition);
                else q.push(board[r][c]);
            }
        }
        steps++;
    }
    return -1;
}
int main(){
    // OP - 4
    vector<vector<int>>board={{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,35,-1,-1,13,-1},{-1,-1,-1,-1,-1,-1},{-1,15,-1,-1,-1,-1}};
    // OP - 1
    vector<vector<int>>board2={{-1,-1},{-1,3}};
    cout<<snakesAndLadders(board2);
    return 0;
}