// LC - 1895 - Medium - Largest Magic Square
#include<iostream>
#include<vector>
using namespace std;
int largestMagicSquare(vector<vector<int>>&grid){
    // TODO:
}
int main(){
    // Output: 3
    vector<vector<int>>grid={{7,1,4,5,6},{2,5,1,6,4},{1,5,4,3,2},{1,2,7,3,4}};
    // Output: 2
    vector<vector<int>>grid2={{5,1,3,1},{9,3,3,1},{1,3,3,8}};
    cout<<largestMagicSquare(grid)<<endl;
    cout<<largestMagicSquare(grid2);
    return 0;
}