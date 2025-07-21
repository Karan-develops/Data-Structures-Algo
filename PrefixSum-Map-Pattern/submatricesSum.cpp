// LC - 1074 - HARD - Number of Submatrices That Sum to Target
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int numSubmatrixSumTarget(vector<vector<int>>&matrix,int target){
    int m=matrix.size(),n=matrix[0].size();

    // Step 1 : Fill Row-wise prefix/Cumulative Sum
    for(int i=0;i<m;i++){
        for(int j=1;j<n;j++){
            matrix[i][j]+=matrix[i][j-1];
        }
    }

    int ans=0;
    
    for(int startCol=0;startCol<n;startCol++){
        for(int j=startCol;j<n;j++){
            // Now comes the concept of "No. of subarrays with sum k"
            unordered_map<int,int>mp;
            mp[0]++;
            int prefixSum=0;

            // Go downwards row wise
            for(int row=0;row<m;row++){
                prefixSum+=(startCol==0?matrix[row][j]:matrix[row][j]-matrix[row][startCol-1]);

                if(mp.count(prefixSum-target)){
                    ans+=mp[prefixSum-target];
                }
                mp[prefixSum]++;
            }
        }
    }
    return ans;
}
int main(){
    // Output: 4
    vector<vector<int>>matrix={{0,1,0},{1,1,1},{0,1,0}};
    int target=0;
    // Output: 5
    vector<vector<int>>matrix2={{1,-1},{-1,1}};
    int target2=0;
    // Output: 0
    vector<vector<int>>matrix3={{904}};
    int target3=0;
    cout<<numSubmatrixSumTarget(matrix,target)<<endl;
    cout<<numSubmatrixSumTarget(matrix2,target2)<<endl;
    cout<<numSubmatrixSumTarget(matrix3,target3);
    return 0;
}