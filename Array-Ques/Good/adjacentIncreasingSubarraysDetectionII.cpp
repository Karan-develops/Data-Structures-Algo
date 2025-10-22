// LC - 3350 - Medium - Adjacent Increasing Subarrays Detection II
// Same as Part 1 Just do BS on Answer
#include<iostream>
#include<vector>
using namespace std;
class BinarySearch{
    int n;
    bool isPossible(vector<int>&nums,int kMid){
        int curr=1;
        int prev=0;

        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i]){
                curr++;
            } else{
                prev=curr;
                curr=1;
            }

            if(curr>=2*kMid) return true;

            if(min(prev,curr)>=kMid) return true;
        }
        return false;
    }
    public:
    int maxIncreasingSubarrays(vector<int>&nums){
        n=nums.size();

        int l=0;
        int r=n/2;
        int ans=0;

        while(l<=r){
            int mid=l+(r-l)/2;

            if(isPossible(nums,mid)){
                ans=mid;
                l=mid+1;
            } else{
                r=mid-1;
            }
        }
        return ans;
    }
};
int main(){
    // Output: 3
    vector<int>nums={2,5,7,8,9,2,3,4,3,1};
    // Output: 2
    vector<int>nums2={1,2,3,4,4,4,4,5,6,7};

    BinarySearch sol;
    cout<<sol.maxIncreasingSubarrays(nums)<<endl;
    cout<<sol.maxIncreasingSubarrays(nums2);
    return 0;
}