// LC - 2016 - Easy - Maximum Difference Between Increasing Elements
#include<iostream>
#include<vector>
using namespace std;
int maximumDifference(vector<int>& nums) {
    int smallest=nums[0],ans=-1;
    for(int i=1;i<nums.size();i++){
        smallest=min(smallest,nums[i]);
        ans=max(ans,nums[i]-smallest);
    }
    return ans==0?-1:ans;
}
int main(){
    // Output: 4
    vector<int>nums={7,1,5,4};
    // Output: -1
    vector<int>nums2={9,4,3,2};
    // Output: 9
    vector<int>nums3={1,5,2,10};
    cout<<maximumDifference(nums)<<endl;
    cout<<maximumDifference(nums2)<<endl;
    cout<<maximumDifference(nums3);
    return 0;
}