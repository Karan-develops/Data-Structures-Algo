// GFG - The Celebrity Problem
#include<iostream>
#include<vector>
using namespace std;
int celebrity(vector<vector<int>>&mat){
    int n=mat.size();
    
    int i=0,j=n-1;

    while(i<j){
        // i know j, so i is not celebrity
        if(mat[i][j]==1) i++;
        // i doesn't know j, so j is not celebrity
        else j--;
    }

    int ans=i;

    for(int i=0;i<n;i++){
        if(i==ans) continue;
        if(mat[ans][i]==1 || mat[i][ans]==0){
            return -1;
        }
    }
    return ans;
}
int main(){
    // Output: 1
    vector<vector<int>>mat={{1,1,0},{0,1,0},{0,1,1}};
    // Output: -1
    vector<vector<int>>mat2={{1,1},{1,1}};
    // Output: 0
    vector<vector<int>>mat3={{1}};
    cout<<celebrity(mat)<<endl;
    cout<<celebrity(mat2)<<endl;
    cout<<celebrity(mat3);
    return 0;
}