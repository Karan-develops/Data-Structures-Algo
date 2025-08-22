// GFG - HARD - Median in a row-wise sorted Matrix
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int median(vector<vector<int>>&matrix){
    int m=matrix.size();
    int n=matrix[0].size();

    int l=INT_MAX,r=INT_MIN;

    for(int i=0;i<m;i++){
        l=min(l,matrix[i][0]);
        r=max(r,matrix[i][n-1]);
    }

    // Median position (1-based)
    int desired=(m*n+1)/2; 

    while(l<r){
        int mid=l+(r-l)/2;
        int count=0;

        // Count how many numbers are <= mid
        for(int i=0;i<m;i++){
            count+=upper_bound(begin(matrix[i]),end(matrix[i]),mid)-begin(matrix[i]);
        }

        if(count<desired) l=mid+1;
        else r=mid;
    }
    return l;
}
int main(){
    // Output: 5
    vector<vector<int>>mat={{1,3,5},{2,6,9},{3,6,9}};
    // Output: 6
    vector<vector<int>>mat2={{2,4,9},{3,6,7},{4,7,10}};
    // Output: 4
    vector<vector<int>>mat3={{3},{4},{8}};
    cout<<median(mat)<<endl;
    cout<<median(mat2)<<endl;
    cout<<median(mat3);
    return 0;
}