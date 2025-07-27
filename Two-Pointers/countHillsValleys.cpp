// LC - 2210 - Easy - Count Hills and Valleys in an Array
#include<iostream>
#include<vector>
using namespace std;
int countHillValley(vector<int>&nums){
    int n=nums.size();

    int i=0;
    int ans=0;

    for(int j=1;j<n-1;j++){
        if((nums[j]>nums[i] && nums[j]>nums[j+1]) ||
            (nums[j]<nums[i] && nums[j]<nums[j+1])){
            ans++;
            i=j;
        }
    }
    return ans;
}
int main(){
    // Output: 3
    vector<int>nums={2,4,1,1,6,5};
    // Output: 0
    vector<int>nums2={6,6,5,5,4,1};
    cout<<countHillValley(nums)<<endl;
    cout<<countHillValley(nums2);
    return 0;
}