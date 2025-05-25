// LC - 34 - Medium - Find First and Last Position of Element in Sorted Array
#include<iostream>
#include<vector>
using namespace std;
class BinarySearch{
    int find_first_position(vector<int>&nums,int target){
        int ans=-1;
        int l=0,r=nums.size()-1;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                ans=mid;
                r=mid-1;
            } else if(nums[mid]>target) r=mid-1;
            else l=mid+1;
        }
        return ans;
    }
    int find_last_position(vector<int>&nums,int target){
        int ans=-1;
        int l=0,r=nums.size()-1;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                ans=mid;
                l=mid+1;
            } else if(nums[mid]>target) r=mid-1;
            else l=mid+1;
        }
        return ans;
    }
    public:
    vector<int> searchRange(vector<int>&nums,int target){
        int l=find_first_position(nums,target);
        int r=find_last_position(nums,target);

        return {l,r};
    }
};
int main(){
    // Output: [3,4]
    vector<int>nums={5,7,7,8,8,10};
    int target=8;
    // Output: [-1,-1]
    vector<int>nums2={5,7,7,8,8,10};
    int target2=6;
    // Output: [-1,-1]
    vector<int>nums3={};
    int target3=0;

    return 0;
}