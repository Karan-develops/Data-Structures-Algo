// LC - 2163 - HARD - Minimum Difference in Sums After Removal of Elements
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
long long minimumDifference(vector<int>&nums){
    int N=nums.size();
    int n=N/3;

    vector<long long>leftMinSum(N,0);
    vector<long long>rightMaxSum(N,0);

    priority_queue<int>maxHeap;
    long long leftSum=0;

    for(int i=0;i<=2*n-1;i++){
        maxHeap.push(nums[i]);
        leftSum+=nums[i];

        if(maxHeap.size()>n){
            leftSum-=maxHeap.top();
            maxHeap.pop();
        }

        leftMinSum[i]=leftSum;
    }

    priority_queue<int,vector<int>,greater<>>minHeap;
    long long rightSum=0;

    for(int i=N-1;i>=n;i--){
        minHeap.push(nums[i]);
        rightSum+=nums[i];

        if(minHeap.size()>n){
            rightSum-=minHeap.top();
            minHeap.pop();
        }

        rightMaxSum[i]=rightSum;
    }

    long long ans=LLONG_MAX;

    for(int i=n-1;i<=2*n-1;i++){
        ans=min(ans,leftMinSum[i]-rightMaxSum[i+1]);
    }
    return ans;
}
int main(){
    // Output: -1
    vector<int>nums={3,1,2};
    // Output: 1
    vector<int>nums2={7,9,5,8,1,3};
    cout<<minimumDifference(nums)<<endl;
    cout<<minimumDifference(nums2);
    return 0;
}