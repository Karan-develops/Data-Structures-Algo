// LC - 766 - Easy - Toeplitz Matrix
// 2 Approaches
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
// Approach 1 - Using Matrix
bool isToeplitzMatrix(vector<vector<int>>&matrix){
    int m=matrix.size();
    int n=matrix[0].size();

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(matrix[i][j]!=matrix[i-1][j-1]){
                return false;
            }
        }
    }
    return true;
}
// Approach 2 - Using Map
bool isToeplitzMatrixMap(vector<vector<int>>&matrix){
    int m=matrix.size();
    int n=matrix[0].size();

    unordered_map<int,int>mp;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mp.count(i-j) && mp[i-j]!=matrix[i][j]){
                return false;
            }
            mp[i-j]=matrix[i][j];
        }
    }
    return true;
}
int main(){
    // Output: true
    vector<vector<int>>matrix={{1,2,3,4},{5,1,2,3},{9,5,1,2}};
    // Output: false
    vector<vector<int>>matrix2={{1,2},{2,2}};
    cout<<isToeplitzMatrix(matrix)<<endl;
    cout<<isToeplitzMatrix(matrix2);
    return 0;
}