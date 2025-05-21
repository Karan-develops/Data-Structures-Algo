// LC - 73 - Medium - Set Matrix Zeroes
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
void setZeroes(vector<vector<int>>&matrix){
    int m=matrix.size(),n=matrix[0].size();
    unordered_map<int,bool>row,col;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==0){
                row[i]=true;
                col[j]=true;
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(row[i] || col[j]) matrix[i][j]=0;
        }
    }
}
int main(){
    // Output: [[1,0,1],[0,0,0],[1,0,1]]
    vector<vector<int>>matrix={{1,1,1},{1,0,1},{1,1,1}};
    // Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
    vector<vector<int>>matrix2={{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    setZeroes(matrix);
    setZeroes(matrix2);
    return 0;
}