// GFG - Maximum Subarray Sum 2
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int maxSubarrSum(vector<int>&arr,int a,int b){
    int n=arr.size();
    
    vector<long long>prefix(n+1,0);
    
    for(int i=0;i<n;i++){
        prefix[i+1]=prefix[i]+arr[i];
    }

    long long ans=LLONG_MIN;
    deque<int>dq;

    for(int i=a;i<=n;i++){
        // Remove indices out of the window [i-b, i-a]
        while(!dq.empty() && dq.front()<i-b){
            dq.pop_front();
        }

        // Maintain deque increasing for prefix sums
        while(!dq.empty() && prefix[dq.back()]>=prefix[i-a]){
            dq.pop_back();
        }
        dq.push_back(i-a);

        ans=max(ans,prefix[i]-prefix[dq.front()]);
    }

    return (int)ans;
}
int main(){
    // Output: 9
    vector<int>arr={4,5,-1,-2,6};
    int a=2,b=4;
    // Output: 8
    vector<int>arr2={-1,3,-1,-2,5,3,-5,2,2};
    int a2=3,b2=5;
    cout<<maxSubarrSum(arr,a,b)<<endl;
    cout<<maxSubarrSum(arr2,a2,b2);
    return 0;
}