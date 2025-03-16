// LC - 2560 - Medium - House Robber IV
// O(log(maxC) * n )
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    int N;
    bool isPossible(vector<int>&nums,int mid,int k){
        int houses=0;
        for(int i=0;i<N;i++){
            if(nums[i]<=mid){
                houses++;
                i++;
            }
        }
        return houses>=k;
    }
    public:
    int minCapability(vector<int>& nums, int k) {
        N=nums.size();
        int l=*min_element(nums.begin(),nums.end());
        int r=*max_element(nums.begin(),nums.end());
        int ans=r;
        while(l<=r){
            //capability
            int mid=l+(r-l)/2;
            if(isPossible(nums,mid,k)==true){
                ans=mid;
                r=mid-1;
            } else{
                l=mid+1;
            }
        }
        return ans;
    }
};
int main(){
    // OP - 5
    vector<int>nums1={2,3,5,9};
    int k1=2;
    // OP - 2
    vector<int>nums2={2,7,9,3,1};
    int k2=2;
    Solution sol;
    cout<<sol.minCapability(nums1,k1)<<endl;
    cout<<sol.minCapability(nums2,k2);
    return 0;
}