// Coin Problem
#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>& arr,int n,int target){
    if(target==0){
        return 0;
    }
    if(target<0){
        return INT_MAX;
    }
    int mini=INT_MAX;
    for(int i=0;i<n;i++){
        int ans=solve(arr,n,target-arr[i]);
        if(ans!=INT_MAX)
        mini=min(mini,ans+1);
    }
    return mini;
}
int solve2(vector<int>& arr,int n,int target,int op,int coins){
    if(op==target){
        return coins;
    }
    if(op>target){
        return INT_MAX;
    }
    int mini=INT_MAX;
    for(int i=0;i<n;i++){
        int ans=solve2(arr,n,target,op+arr[i],coins+1);
        if(ans!=INT_MAX)
        mini=min(mini,ans);
    }
    return mini;
}
int main(){
    vector<int>arr{1,2};
    int n=arr.size();
    int target=5;
    // int ans=solve(arr,n,target);
    int op=0;
    int ans=solve2(arr,n,target,op,0);
    cout<<"Answer is: "<<ans;
    return 0;
}