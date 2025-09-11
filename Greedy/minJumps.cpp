// GFG - Minimum Jumps
#include<iostream>
#include<vector>
using namespace std;
int minJumps(vector<int>&arr){
    int n=arr.size();
    
    if(n<=1) return 0;
    if(arr[0]==0) return -1;

    int maxReach=arr[0];
    int steps=arr[0];
    int jumps=1;

    for(int i=1;i<n;i++){
        if(i==n-1) return jumps;

        maxReach=max(maxReach,i+arr[i]);
        steps--;

        if(steps==0){
            jumps++;
            if(i>=maxReach) return -1;
            steps=maxReach-i;
        }
    }
    return -1;
}
int main(){
    // Output: 3 
    vector<int>arr={1,3,5,8,9,2,6,7,6,8,9};
    // Output: 2 
    vector<int>arr2={1,4,3,2,6,7};
    // Output: -1
    vector<int>arr3={0,10,20};
    cout<<minJumps(arr)<<endl;
    cout<<minJumps(arr2)<<endl;
    cout<<minJumps(arr3);
    return 0;
}