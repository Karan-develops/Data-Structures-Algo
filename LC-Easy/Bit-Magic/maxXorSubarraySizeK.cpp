// GFG - Medium - Max Xor Subarray of size K
#include<iostream>
#include<vector>
using namespace std;
int maxSubarrayXOR(vector<int>&arr,int k){
    int n=arr.size();
    
    int i=0,j=0;
    int curr=0,ans=0;
    
    while(j<n){
        curr^=arr[j];
        
        if(j-i+1==k){
            ans=max(ans,curr);
            curr^=arr[i];
            i++;
        }
        
        j++;
    }
    
    return ans;
}
int main(){
    // Output: 15
    int k=3;
    vector<int>arr={2,5,8,1,1,3};
    // Output: 6
    int k2=2;
    vector<int>arr2={1,2,4,5,6};
    cout<<maxSubarrayXOR(arr,k)<<endl;
    cout<<maxSubarrayXOR(arr2,k2);
    return 0;
}