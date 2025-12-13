// GFG - Easy - Swap diagonals
#include<iostream>
#include<vector>
using namespace std;
void swapDiagonal(vector<vector<int>>&mat){
    int n=mat.size();
    
    for(int i=0;i<n;i++){
        swap(mat[i][i],mat[i][n-i-1]);
    }
}
int main(){
    // Output: [[2, 1, 0],[3, 4, 5],[8, 7, 6]]
    vector<vector<int>>mat={{0,1,2},{3,4,5},{6,7,8}};
    // Output: [[3, 2],[4, 5]] 
    vector<vector<int>>mat2={{2,3},{5,4}};
    return 0;
}