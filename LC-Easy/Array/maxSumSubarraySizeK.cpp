// GFG - Easy - Max Sum Subarray of size K
#include<iostream>
#include<vector>
using namespace std;
int maxSubarraySum(vector<int>&arr,int k){
    int n=arr.size();
    
    int i=0,j=0;
    
    int curr=0;
    int ans=0;
    
    while(j<n){
        curr+=arr[j];
        
        if(j-i+1==k){
            ans=max(ans,curr);
            curr-=arr[i];
            i++;
        }
        
        j++;
    }
    
    return ans;
}
int main(){
    // Output: 700
    int k=2;
    vector<int>arr={100,200,300,400};
    // Output: 39
    int k2=4;
    vector<int>arr2={1,4,2,10,23,3,1,0,20};
    // Output: 400
    int k3=1;
    vector<int>arr3={100,200,300,400};
    cout<<maxSubarraySum(arr,k)<<endl;
    cout<<maxSubarraySum(arr2,k2)<<endl;
    cout<<maxSubarraySum(arr3,k3);
    return 0;
}