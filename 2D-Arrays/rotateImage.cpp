#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void rotate(vector<vector<int>>& matrix) {
    int n=matrix.size();
    // Transpose
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    // Reverse
    for(auto &row:matrix){
        reverse(begin(row),end(row));
    }
}
int main(){
    // OP - [[7,4,1],[8,5,2],[9,6,3]]
    vector<vector<int>>nums{{1,2,3},{4,5,6},{7,8,9}};
    rotate(nums);
    for(auto &vec:nums){
        for(int &i:vec) cout<<i<<" ";
        cout<<endl;
    }
}