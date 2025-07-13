// GFG - Maximum sum of elements not part of LIS
#include<iostream>
#include<vector>
using namespace std;
int nonLisMaxSum(vector<int>&arr){
    int n=arr.size();
    int total=0;
    
    vector<int>minSum(n,0);
    for(int i=0;i<n;i++){
        minSum[i]=arr[i];
        total+=arr[i];
    }
    
    vector<int>dp(n,1);
    int minLISSum=total;
    int maxLen=-1;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
                if(dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    minSum[i]=minSum[j]+arr[i];
                } else if(dp[i]==dp[j]+1){
                    minSum[i]=min(minSum[i],minSum[j]+arr[i]);
                }
            }
        }
        if(maxLen<dp[i]){
            maxLen=dp[i];
            minLISSum=minSum[i];
        } else if(maxLen==dp[i]){
            minLISSum=min(minLISSum,minSum[i]);
        }
    }
    return total-minLISSum;
}
int main(){
    // Output: 10
    vector<int>arr={4,6,1,2,3,8};
    // Output: 14
    vector<int>arr2={5,4,3,2,1};
    cout<<nonLisMaxSum(arr)<<endl;
    cout<<nonLisMaxSum(arr2);
    return 0;
}