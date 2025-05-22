// LC - 1310 - Medium - XOR Queries of a Subarray
#include<iostream>
#include<vector>
using namespace std;
vector<int> xorQueries(vector<int>&arr,vector<vector<int>>&queries){
    int n=arr.size();
    vector<int>cumXor(n,0);
    cumXor[0]=arr[0];
    for(int i=1;i<n;i++){
        cumXor[i]=cumXor[i-1]^arr[i];
    }
    vector<int>ans;
    for(auto &vec:queries){
        int l=vec[0];
        int r=vec[1];

        int xor_val=cumXor[r]^(l==0?0:cumXor[l-1]);
        
        ans.push_back(xor_val);
    }
    return ans;
}
int main(){
    // Output: [2,7,14,8]
    vector<int>arr={1,3,4,8};
    vector<vector<int>>queries={{0,1},{1,2},{0,3},{3,3}};
    // Output: [8,0,4,4]
    vector<int>arr2={4,8,2,10};
    vector<vector<int>>queries2={{2,3},{1,3},{0,0},{0,3}};
    return 0;
}