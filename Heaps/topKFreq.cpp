// LC - 347 - Medium - Top K Frequent Elements
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int>mp;

    for(int &i:nums) mp[i]++;

    priority_queue<pair<int,int>>pq;

    for(auto &it:mp){
        pq.push({it.second,it.first});
    }

    vector<int>ans;
    while(k--){
        int num=pq.top().second;
        pq.pop();
        ans.push_back(num);
    }
    return ans;
}
int main(){
    // Output: [1,2]
    vector<int>nums={1,1,1,2,2,3};
    int k=2;
    // Output: [1]
    vector<int>nums2={1};
    int k2=1;
    return 0;
}