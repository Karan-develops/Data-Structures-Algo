// GFG - Sum of Subarrays
#include<iostream>
#include<vector>
using namespace std;
int subarraySum(vector<int>&arr){
    int n=arr.size();
    int ans=0;
    
    for(int i=0;i<n;i++){
        ans+=arr[i]*(i+1)*(n-i);
    }
    return ans;
}
int main(){
    // Output: 20
    vector<int>arr={1,2,3};
    // Output: 8
    vector<int>arr2={1,3};
    cout<<subarraySum(arr)<<endl;
    cout<<subarraySum(arr2);
    return 0;
}