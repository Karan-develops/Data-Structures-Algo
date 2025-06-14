// LC - 704 - Easy - Binary Search
#include<iostream>
#include<vector>
using namespace std;
class BinarySearch{
    int solve(vector<int>&nums,int target,int l,int r){
        if(l>r) return -1;
        
        int mid=l+(r-l)/2;
        if(nums[mid]==target) return mid;

        if(nums[mid]>target) return solve(nums,target,l,mid-1);

        return solve(nums,target,mid+1,r);
    }
    public:
    int iterative(vector<int>&nums,int target){
        int l=0,r=nums.size()-1;

        while(l<=r){
            int mid=l+(r-l)/2;

            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) r=mid-1;
            else l=mid+1;
        }
        return -1;
    }
    int recursive(vector<int>&nums,int target){
        return solve(nums,target,0,nums.size()-1);
    }
};
int main(){
    // Output: 4
    vector<int>nums={-1,0,3,5,9,12};
    int target=9;
    // Output: -1
    vector<int>nums2={-1,0,3,5,9,12};
    int target2=2;

    BinarySearch sol;
    cout<<sol.iterative(nums,target)<<endl;
    cout<<sol.recursive(nums2,target2);
    return 0;
}