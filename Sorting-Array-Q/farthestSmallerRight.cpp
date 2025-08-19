// GFG - Farthest Smaller Right
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> farMin(vector<int>&arr){
    int n=arr.size();
        
    vector<pair<int,int>>v;
    
    for(int i=0;i<n;i++){
        v.push_back({arr[i],i});
    }
    
    sort(begin(v),end(v));
    
    vector<int>ans(n,-1);
    
    int maxi=v[0].second;
    
    for(int i=1;i<n;i++){
        if(maxi>v[i].second){
            ans[v[i].second]=maxi;
        }
        maxi=max(maxi,v[i].second);
    }
    return ans;
}
int main(){
    // Output: [2, 4, -1, 4, -1]
    vector<int>arr={2,5,1,3,2};
    // Output: [4, 4, 4, 4, -1]
    vector<int>arr2={2,3,5,4,1};
    return 0;
}