// LC - 3578 - Medium - Count Partitions With Max-Min Difference at Most K
// Partition DP
// 3 Approaches
#include<iostream>
#include<vector>
#include<deque>
using namespace std;
// Approach 1 - Top Down - (Rec+Memo) - TLE
class DP{
    int n;
    const int M=1e9+7;
    vector<long long>dp;
    long long solve(vector<int>&nums,int k,int i){
        // Successfully formed partitions till end
        if(i>=n) return 1;

        if(dp[i]!=-1) return dp[i];

        long long ans=0;
        int minE=INT_MAX;
        int maxE=INT_MIN;

        for(int j=i;j<n;j++){
            minE=min(minE,nums[j]);
            maxE=max(maxE,nums[j]);

            if(maxE-minE>k) break;

            ans=(ans+solve(nums,k,j+1))%M;
        }

        return dp[i]=ans;
    }
    public:
    int countPartitions(vector<int>&nums,int k){
        n=nums.size();
        dp.resize(n+1,-1);

        return solve(nums,k,0);
    }
};
// Approach 2 - Bottom Up - TLE
class BottomUp{
    const int M=1e9+7;
    public:
    int countPartitions(vector<int>&nums,int k){
        int n=nums.size();
        
        vector<long long>dp(n+1);
        dp[n]=1;

        for(int i=n-1;i>=0;i--){
            long long count=0;
            int minEl=INT_MAX;
            int maxEl=INT_MIN;

            // Same loop as recursion
            for(int j=i;j<n;j++){
                minEl=min(minEl,nums[j]);
                maxEl=max(maxEl,nums[j]);

                if(maxEl-minEl>k) break;

                // Same transition: solve(j+1)
                count=(count+dp[j+1])%M;
            }

            dp[i]=count;
        }

        // Same as solve(0)
        return dp[0];
    }
};
// Approach 3 - DP + Sliding Window
class SlidingDP{
    const int M=1e9+7;
    public:
    int countPartitions(vector<int>&nums,int k){
        int n=nums.size();

        vector<int>dp(n+1,0);
        vector<int>prefix(n+1,0);

        dp[0]=1,prefix[0]=1;

        deque<int>maxDq,minDq;
        int i=0,j=0;

        while(j<n){
            while(!maxDq.empty() && nums[j]>nums[maxDq.back()]){
                maxDq.pop_back();
            }
            maxDq.push_back(j);

            while(!minDq.empty() && nums[j]<nums[minDq.back()]){
                minDq.pop_back();
            }
            minDq.push_back(j);

            while(nums[maxDq.front()]-nums[minDq.front()]>k){
                i++;
                if(!maxDq.empty() && maxDq.front()<i) maxDq.pop_front();
                if(!minDq.empty() && minDq.front()<i) minDq.pop_front();
            }

            dp[j+1]=(prefix[j]-(i>0?prefix[i-1]:0)+M)%M;
            prefix[j+1]=(prefix[j]+dp[j+1])%M;

            j++;
        }

        return dp[n];
    }
};
int main(){
    // Output: 6
    vector<int>nums={9,4,1,3,7};
    int k=4;
    // Output: 2
    vector<int>nums2={3,3,4};
    int k2=0;

    SlidingDP sol;
    cout<<sol.countPartitions(nums,k)<<endl;
    cout<<sol.countPartitions(nums2,k2);
    return 0;
}