// GFG - Medium - Row with max 1s
#include<iostream>
#include<vector>
using namespace std;
int rowWithMax1s(vector<vector<int>>&arr){
    int n=arr.size();
    
    pair<int,int>ans={-1,0};
    
    for(int i=0;i<n;i++){
        int curr=0;
        for(int j=0;j<arr[i].size();j++){
            if(arr[i][j]==1){
                curr=arr[i].size()-j;
                break;
            }
        }
        
        if(curr>ans.second){
            ans.first=i;
            ans.second=curr;
        }
    }
    
    return ans.first;
}
int main(){
    // Output: 2
    vector<vector<int>>arr={{0,1,1,1},{0,0,1,1},{1,1,1,1},{0,0,0,0}};
    // Output: 1
    vector<vector<int>>arr2={{0,0},{1,1}};
    // Output: -1
    vector<vector<int>>arr3={{0,0},{0,0}};
    cout<<rowWithMax1s(arr)<<endl;
    cout<<rowWithMax1s(arr2)<<endl;
    cout<<rowWithMax1s(arr3);
    return 0;
}