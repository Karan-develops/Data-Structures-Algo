// GFG - Medium - Count distinct elements in every window
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> countDistinct(vector<int>&arr,int k){
    int n=arr.size();
    
    unordered_map<int,int>mp;
    vector<int>ans;
    
    for(int i=0;i<k;i++){
        mp[arr[i]]++;
    }
    
    ans.push_back(mp.size());
    
    int i=0,j=k;
    
    while(j<n){
        mp[arr[i]]--;
        
        if(mp[arr[i]]==0){
            mp.erase(arr[i]);
        }
        
        i++;
        mp[arr[j]]++;
        j++;
        
        ans.push_back(mp.size());
    }
    
    return ans;
}
int main(){
    // Output: [3,4,4,3]
    int k=4;
    vector<int>arr={1,2,1,3,4,2,3};
    // Output: [2,1]
    int k2=2;
    vector<int>arr2={4,1,1};
    // Output: [1,1,1]
    int k3=3;
    vector<int>arr3={1,1,1,1,1};
    return 0;
}