// GFG - Search in fully rotated sorted 2D matrix
#include<iostream>
#include<vector>
using namespace std;
bool searchMatrix(vector<vector<int>>&mat,int x){
    int m=mat.size();
    int n=mat[0].size();
    
    int l=0;
    int r=m*n-1;
    
    while(l<=r){
        int mid=l+(r-l)/2;
        int ele=mat[mid/n][mid%n];
        
        int start=mat[l/n][l%n];
        int end=mat[r/n][r%n];
        
        if(ele==x) return true;
        
        if(ele>end){
            if(start<=x && ele>x) r=mid-1;
            else l=mid+1;
        } else{
            if(end>=x && x>ele) l=mid+1;
            else r=mid-1;
        }
    }
    return false;
}
int main(){
    // Output: true
    int x=3;
    vector<vector<int>>mat={{7,8,9,10},{11,12,13,1},{2,3,4,5}}; 
    // Output: false
    int x2=10;
    vector<vector<int>>mat2={{6,7,8},{9,1,2},{3,4,5}};
    cout<<searchMatrix(mat,x)<<endl;
    cout<<searchMatrix(mat2,x2);
    return 0;
}