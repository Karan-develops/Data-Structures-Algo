// LC - 118 - Easy - Pascal's Triangle
// Application : We can use Pascal's Triangle to find nCr in constant time
// Example n=4, r=2 => 4th row 2nd column
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> generate(int numRows){
    vector<vector<int>>ans(numRows);

    for(int i=0;i<numRows;i++){
        ans[i]=vector<int>(i+1,1);

        for(int j=1;j<i;j++){
            ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
        }
    }
    return ans;
}
int main(){
    // Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
    int numRows=5;
    // Output: [[1]]
    int numRows2=1;
    return 0;
}