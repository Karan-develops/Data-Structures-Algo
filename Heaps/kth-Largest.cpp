// LC - 215 - Medium - Kth Largest Element in an Array
// Also Solved Using Quick-Select in Algorithms.
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int findKthLargest(vector<int>&nums,int k){
    priority_queue<int,vector<int>,greater<>>pq;

    for(int &i:nums){
        pq.push(i);
        if(pq.size()>k) pq.pop();
    }
    return pq.top();
}
int main(){
    // Output: 5
    vector<int>nums={3,2,1,5,6,4};
    int k=2;
    // Output: 4
    vector<int>nums2={3,2,3,1,2,4,5,5,6};
    int k2=4;
    cout<<findKthLargest(nums,k)<<endl;
    cout<<findKthLargest(nums2,k2);
    return 0;
}