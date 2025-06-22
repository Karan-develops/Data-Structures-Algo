// LC - 2099 - Easy - Find Subsequence of Length K With the Largest Sum
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<int,int>P;
vector<int> maxSubsequence(vector<int>&nums,int k){
    int n=nums.size();
    // Min-Heap
    priority_queue<P,vector<P>,greater<P>>pq;

    // Min-Heap Will pop small elements
    for(int i=0;i<n;i++){
        pq.push({nums[i],i});
        if(pq.size()>k) pq.pop();
    }

    vector<int>indices;
    while(!pq.empty()){
        indices.push_back(pq.top().second);
        pq.pop();
    }

    sort(begin(indices),end(indices));

    vector<int>ans;
    for(int i=0;i<k;i++){
        int idx=indices[i];
        ans.push_back(nums[idx]);
    }
    return ans;
}
int main(){
    // Output: [3,3]
    vector<int>nums={2,1,3,3};
    int k=2;
    // Output: [-1,3,4]
    vector<int>nums2={-1,-2,3,4};
    int k2=3;
    // Output: [3,4]
    vector<int>nums3={3,4,3,3};
    int k3=2;
    return 0;
}