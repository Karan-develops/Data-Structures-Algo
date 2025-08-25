// LC - 1329 - Medium - Sort the Matrix Diagonally
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
vector<vector<int>> diagonalSort(vector<vector<int>>&mat){
    int m=mat.size();
    int n=mat[0].size();

    unordered_map<int,vector<int>>mp;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            mp[i-j].push_back(mat[i][j]);
        }
    }

    for(auto &it:mp){
        sort(begin(it.second),end(it.second));
    }

    // Put in reverse order bcoz they are sorted in a
    for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            mat[i][j]=mp[i-j].back();

            mp[i-j].pop_back();
        }
    }
    return mat;
}
int main(){
    // Output: {1,1,1,1},{1,2,2,2},{1,2,3,3}}
    vector<vector<int>>mat={{3,3,1,1},{2,2,1,2},{1,1,1,2}};
    // Output: {{5,17,4,1,52,7},{11,11,25,45,8,69},{14,23,25,44,58,15},{22,27,31,36,50,66},{84,28,75,33,55,68}}
    vector<vector<int>>mat2={{11,25,66,1,69,7},{23,55,17,45,15,52},{75,31,36,44,58,8},{22,27,33,25,68,4},{84,28,14,11,5,50}};
    return 0;
}