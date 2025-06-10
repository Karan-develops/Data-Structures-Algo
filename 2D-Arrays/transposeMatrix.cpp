// LC - 867 - Easy - Transpose Matrix
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> transpose(vector<vector<int>>&matrix){
    int m=matrix.size(),n=matrix[0].size();
    vector<vector<int>>ans;

    for(int i=0;i<n;i++){
        vector<int>temp;
        for(int j=0;j<m;j++){
            temp.push_back(matrix[j][i]);
        }
        ans.push_back(temp);
    }
    return ans;
}
int main(){
    // Output: [[1,4,7],[2,5,8],[3,6,9]]
    vector<vector<int>>matrix={{1,2,3},{4,5,6},{7,8,9}};
    // Output: [[1,4],[2,5],[3,6]]
    vector<vector<int>>matrix2={{1,2,3},{4,5,6}};
    return 0;
}