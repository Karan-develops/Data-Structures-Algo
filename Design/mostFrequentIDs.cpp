// LC - 3092 - Medium - Most Frequent IDs
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
typedef long long ll;
vector<long long> mostFrequentIDs(vector<int>&nums,vector<int>&freq){
    int n=nums.size();

    // id->freq
    unordered_map<ll,ll>mp;
    // {freq,id}
    priority_queue<pair<ll,ll>>pq;
    vector<ll>ans;

    for(int i=0;i<n;i++){
        int id=nums[i];
        int fq=freq[i];

        mp[id]+=fq;
        pq.push({mp[id],id});

        while(!pq.empty() && mp[pq.top().second]!=pq.top().first){
            pq.pop();
        }

        ans.push_back(pq.top().first);
    }
    return ans;
}
int main(){
    // Output: [3,3,2,2]
    vector<int>nums={2,3,2,1},freq={3,2,-3,1};
    // Output: [2,0,1]
    vector<int>nums2={5,5,3},freq2={2,-2,1};
    return 0;
}