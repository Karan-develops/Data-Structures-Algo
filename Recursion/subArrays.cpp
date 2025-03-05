#include<iostream>
#include<vector>
using namespace std;
void subArrays(vector<int>& arr,vector<int>& ans,vector<int>store,int i,int n){
    if(i>=n){
        ans.push_back(0);
        for(auto i:store){
            ans.push_back(i);
        }
        ans.push_back(0);
        return;
    }
    subArrays(arr,ans,store,i+1,n);
    store.push_back(arr[i]);
    subArrays(arr,ans,store,i+1,n);
}
void printArray(vector<int>&ans){
    for(auto i:ans){
        if(i==0){
            cout<<" | ";
            continue;
        }
        cout<<i<<",";
    }
}
int main(){
    vector<int>arr{1,2,3,4,5};
    vector<int>store;
    vector<int>ans;
    int n=5;
    subArrays(arr,ans,store,0,n);
    printArray(ans);
    return 0;
}