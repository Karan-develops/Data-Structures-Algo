// LC - 74 - Medium - Search a 2D Matrix
#include<iostream>
#include<vector>
using namespace std;
bool searchMatrix(vector<vector<int>>&matrix,int target){
    int m=matrix.size(),n=matrix[0].size();

    int l=0,r=m*n-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(matrix[mid/n][mid%n]==target){
            return true;
        } else if(matrix[mid/n][mid%n]<target){
            l=mid+1;
        } else r=mid-1;
    }
    return false;
}
int main(){
    // Output: true
    vector<vector<int>>matrix={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target=3;
    // Output: false
    vector<vector<int>>matrix2={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target2=13;
    cout<<searchMatrix(matrix,target)<<endl;
    cout<<searchMatrix(matrix2,target2);
    return 0;
}