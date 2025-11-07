// LC - 3318 - Medium - Find X-Sum of All K-Long Subarrays I
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
class Heap{
    int K,X;
    typedef pair<int,int>P;
    int solve(vector<int>&nums,int i,int j){
        unordered_map<int,int>mp;
        int sum=0;

        for(int i_=i;i_<=j;i_++){
            mp[nums[i_]]++;
            sum+=nums[i_];
        }

        if(mp.size()<X) return sum;

        priority_queue<P,vector<P>,greater<P>>pq;

        for(auto &it:mp){
            pq.push({it.second,it.first});

            if(pq.size()>X) pq.pop();
        }

        int ans=0;

        while(!pq.empty()){
            int value=pq.top().second*pq.top().first;
            pq.pop();

            ans+=value;
        }

        return ans;
    }
    public:
    vector<int> findXSum(vector<int>&nums,int k,int x){
        int n=nums.size();
        K=k,X=x;

        vector<int>ans(n-k+1);

        for(int i=0;i<=n-k;i++){
            ans[i]=solve(nums,i,i+k-1);
        }

        return ans;
    }
};
int main(){
    // Output: [6,10,12]
    vector<int>nums={1,1,2,2,3,4,2,3};
    int k=6,x=2;
    // Output: [11,15,15,15,12]
    vector<int>nums2={3,8,7,8,7,5};
    int k2=2,x2=2;
    return 0;
}