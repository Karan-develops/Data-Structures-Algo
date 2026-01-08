// GFG - Medium - Count Subarray with k odds
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int countSubarrays(vector<int>&arr,int k){
    int n=arr.size();
    
    for(int &i:arr){
        if(i&1) i=1;
        else i=0;
    }
    
    unordered_map<int,int>mp;
    mp[0]=1;
    
    int ans=0,sum=0;
    
    for(int i=0;i<n;i++){
        sum += arr[i];
        
        if(mp.count(sum-k)){
            ans+=mp[sum-k];
        }
        
        mp[sum]++;
    }

    return ans;
}
int main(){
    // Output: 2
    int k=2;
    vector<int>arr={2,5,6,9};
    // Output: 8
    int k2=2;
    vector<int>arr2={2,2,5,6,9,2,11};
    cout<<countSubarrays(arr,k)<<endl;
    cout<<countSubarrays(arr2,k2);
    return 0;
}