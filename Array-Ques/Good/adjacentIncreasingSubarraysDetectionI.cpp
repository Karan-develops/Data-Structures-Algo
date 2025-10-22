// LC - 3349 - Easy - Adjacent Increasing Subarrays Detection I
// 2 Approaches
#include<iostream>
#include<vector>
using namespace std;
// Approach 1 - Brute Force
class BruteForce{
    bool isIncreasing(vector<int>&nums,int s,int e){
        for(int i=s+1;i<e;i++){
            if(nums[i-1]>=nums[i]) return false;
        }
        return true;
    }
    public:
    bool hasIncreasingSubarrays(vector<int>&nums,int k){
        int n=nums.size();

        for(int i=0;i+2*k<=n;i++){
            bool first=isIncreasing(nums,i,i+k);
            bool second=isIncreasing(nums,i+k,i+2*k);

            if(first && second) return true;
        }

        return false;
    }
};
// Approach 2 - Optimal
class Array{
    public:
    bool hasIncreasingSubarrays(vector<int>&nums,int k){
        int n=nums.size();

        int curr=1;
        int prev=0;

        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i]){
                curr++;
            } else{
                prev=curr;
                curr=1;
            }

            if(curr>=2*k) return true;

            if(min(curr,prev)>=k) return true;
        }

        return false;
    }
};
int main(){
    // Output: true
    vector<int>nums={2,5,7,8,9,2,3,4,3,1};
    int k=3;
    // Output: false
    vector<int>nums2={1,2,3,4,4,4,4,5,6,7};
    int k2=5;

    Array sol;
    cout<<sol.hasIncreasingSubarrays(nums,k)<<endl;
    cout<<sol.hasIncreasingSubarrays(nums2,k2);
    return 0;
}