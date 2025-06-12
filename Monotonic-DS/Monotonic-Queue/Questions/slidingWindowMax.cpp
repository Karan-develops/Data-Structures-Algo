// LC - 239 - HARD - Sliding Window Maximum
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> maxSlidingWindow(vector<int>&nums,int k){
    int n=nums.size();
    vector<int>ans;
    deque<int>dq;

    for(int i=0;i<n;i++){
        // Out of Window
        while(!dq.empty() && dq.front()<=i-k){
            dq.pop_front();
        }

        while(!dq.empty() && nums[dq.back()]<nums[i]){
            dq.pop_back();
        }

        // Pushing Index
        dq.push_back(i);

        if(i>=k-1){
            ans.push_back(nums[dq.front()]);
        }
    }
    return ans;
}
int main(){
    // Output: [3,3,5,5,6,7]
    vector<int>nums={1,3,-1,-3,5,3,6,7};
    int k=3;
    // Output: [1]
    vector<int>nums2={1};
    int k2=1;
    return 0;
}