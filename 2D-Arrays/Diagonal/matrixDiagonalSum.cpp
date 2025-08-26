// LC - 1572 - Easy - Matrix Diagonal Sum
#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
int diagonalSum(vector<vector<int>>&mat){
    int n=mat.size();
    int i=0;
    
    // Adding Row by Row
    /*
    1 . . . 1
    . 1 . 1 .
    . . 1 . .
    . 1 . 1 .
    1 . . . 1
    */ 
    auto lambda=[&](int sum,vector<int>vec){
        sum+=vec[i];
        // To avoid adding twice (Centre Element)
        if(i!=n-i-1) sum+=vec[n-i-1];
        i++;
        return sum;
    };

    int ans=accumulate(mat.begin(),mat.end(),0,lambda);
    return ans;
}
int main(){
    // Output: 25
    vector<vector<int>>mat={{1,2,3},{4,5,6},{7,8,9}};
    // Output: 8
    vector<vector<int>>mat2={{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}};
    // Output: 5
    vector<vector<int>>mat3={{5}};
    cout<<diagonalSum(mat)<<endl;
    cout<<diagonalSum(mat2)<<endl;
    cout<<diagonalSum(mat3);
    return 0;
}