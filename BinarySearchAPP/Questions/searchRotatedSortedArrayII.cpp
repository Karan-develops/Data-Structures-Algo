// LC - 81 - Medium - Search in Rotated Sorted Array II
#include<iostream>
#include<vector>
using namespace std;
class BinarySearch{
    int findPivot(vector<int>&nums,int l,int r){
        while(l<r){
            while(l<r && nums[l]==nums[l+1]) l++;
            while(l<r && nums[r]==nums[r-1]) r--;

            int mid=l+(r-l)/2;

            if(nums[mid]>nums[r]) l=mid+1;
            else r=mid;
        }
        return r;
    }
    bool binarySearch(vector<int>&nums,int l,int r,int target){
        while(l<=r){
            int mid=l+(r-l)/2;

            if(nums[mid]==target) return true;
            else if(nums[mid]>target) r=mid-1;
            else l=mid+1;
        }
        return false;
    }
    public:
    bool search(vector<int>&nums,int target){
        int n=nums.size();

        int pivot=findPivot(nums,0,n-1);

        if(binarySearch(nums,0,pivot-1,target)) return true;

        return binarySearch(nums,pivot,n-1,target);
    }
};
int main(){
    // Output: true
    vector<int>nums={2,5,6,0,0,1,2};
    int target=0;
    // Output: false
    vector<int>nums2={2,5,6,0,0,1,2};
    int target2=3;

    BinarySearch sol;
    cout<<sol.search(nums,target)<<endl;
    cout<<sol.search(nums2,target2);
    return 0;
}