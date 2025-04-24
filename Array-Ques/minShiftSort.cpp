// LC - 2855 - Easy - Minimum Right Shifts to Sort the Array
#include<iostream>
#include<vector>
using namespace std;
int minimumRightShifts(vector<int>&nums){
    int n=nums.size();
    int i=0;
    while(i+1<n && nums[i]<nums[i+1]) i++;

    if(i==n-1) return 0;
    i++;
    
    int pivot=i;

    while(i+1<n && nums[i]<nums[i+1]) i++;
    if(i!=n-1) return -1;
    
    if(nums[pivot]<nums[0] && nums[n-1]<nums[0]) return n-pivot;
    return -1;
}
int main(){
    // Output: 2
    vector<int>nums={3,4,5,1,2};
    // Output: 0
    vector<int>nums2={1,3,5};
    // Output: -1
    vector<int>nums3={2,1,4};
    cout<<minimumRightShifts(nums)<<endl;
    cout<<minimumRightShifts(nums2)<<endl;
    cout<<minimumRightShifts(nums3);
    return 0;
}