// Ternary Search
// Calculate 2 Mids
// (1) [l+(r-l)/3] || (2) [r-(r-l)/3]
#include<iostream>
#include<vector>
using namespace std;
int ternarySearch(vector<int>&nums,int target){
    int l=0;
    int r=nums.size()-1;
    
    while(l<=r){
        int mid1=l+(r-l)/3;
        int mid2=r-(r-l)/3;
        
        if(nums[mid1]==target) return mid1;
        if(nums[mid2]==target) return mid2;
        
        if(target<nums[mid1]) r=mid1-1;
        else if(target>nums[mid2]) l=mid2+1;
        else {
            l=mid1+1;
            r=mid2-1;
        }
    }
    return -1;
}
int main(){
    // OP - 3
    vector<int>nums={1,3,4,5,6};
    int target=5;
    // OP - -1
    vector<int>nums2={1,3,4,5,6};
    int target2=2;
    cout<<ternarySearch(nums,target)<<endl;
    cout<<ternarySearch(nums2,target2);
    return 0;
}