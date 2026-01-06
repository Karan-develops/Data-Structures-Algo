// LC - 1975 - Medium - Maximum Matrix Sum
#include<iostream>
#include<vector>
using namespace std;
long long maxMatrixSum(vector<vector<int>>&matrix){
    int m=matrix.size();
    int n=matrix[0].size();

    long long sum=0;
    int countNegatives=0; 
    int smallestAbsoluteValue=INT_MAX;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            sum+=abs(matrix[i][j]);

            countNegatives+=matrix[i][j]<0?1:0;

            smallestAbsoluteValue=min(smallestAbsoluteValue,abs(matrix[i][j]));

        }
    }

    if(countNegatives%2==0){
        return sum;
    }

    return sum-2*smallestAbsoluteValue;
}
int main(){
    // Output: 4
    vector<vector<int>>matrix={{1,-1},{-1,1}};
    // Output: 16
    vector<vector<int>>matrix2={{1,2,3},{-1,-2,-3},{1,2,3}};
    cout<<maxMatrixSum(matrix)<<endl;
    cout<<maxMatrixSum(matrix2);
    return 0;
}