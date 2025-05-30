// LC - 2593 - Medium - Find Score of an Array After Marking All Elements
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,int>P;
long long findScore(vector<int>& nums) {
    long long ans=0;
    int n=nums.size();

    priority_queue<P,vector<P>,greater<P>>pq;
    for(int i=0;i<n;i++){
        pq.push({nums[i],i});
    }

    while(!pq.empty()){
        int top=pq.top().first;
        int idx=pq.top().second;
        pq.pop();

        if(nums[idx]!=-1){
            ans+=top;
            nums[idx]=-1;
            if(idx-1>=0) nums[idx-1]=-1;
            if(idx+1<n) nums[idx+1]=-1;
        }
    }
    return ans;
}
int main(){
    // Output: 7
    vector<int>nums={2,1,3,4,5,2};
    // Output: 5
    vector<int>nums2={2,3,5,1,3,2};
    cout<<findScore(nums)<<endl;
    cout<<findScore(nums2);
    return 0;
}