// LC - 1007 - Medium - Minimum Domino Rotations For Equal Row
#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>&tops,vector<int>&bottoms,int val){
    int n=tops.size();
    int swapTop=0,swapBottom=0;

    for(int i=0;i<n;i++){
        if(tops[i]!=val && bottoms[i]!=val) return -1;
        else if(tops[i]!=val) swapTop++;
        else if(bottoms[i]!=val) swapBottom++;
    }
    return min(swapTop,swapBottom);
}
int minDominoRotations(vector<int>&tops,vector<int>&bottoms){
    int ans=INT_MAX;
    for(int i=1;i<=6;i++){
        int swaps=solve(tops,bottoms,i);
        if(swaps!=-1) ans=min(ans,swaps);
    }
    return ans==INT_MAX?-1:ans;
}
int main(){
    // Output: 2
    vector<int>tops={2,1,2,4,2,2},bottoms={5,2,6,2,3,2};
    // Output: -1
    vector<int>tops2={3,5,1,2,3},bottoms2={3,6,3,3,4};
    cout<<minDominoRotations(tops,bottoms)<<endl;
    cout<<minDominoRotations(tops2,bottoms2);
    return 0;
}