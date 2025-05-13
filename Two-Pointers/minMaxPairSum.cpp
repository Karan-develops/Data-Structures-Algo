// LC - 1877 - Medium - Minimize Maximum Pair Sum in Array
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int minPairSum(vector<int>& nums) {
    int n=nums.size();
    int ans=0;
    sort(begin(nums),end(nums));

    for(int i=0;i<n/2;i++){
        ans=max(ans,nums[i]+nums[n-i-1]);
    }
    return ans;
}
int main(){
    // Output: 7
    vector<int>nums={3,5,2,3};
    // Output: 8
    vector<int>nums2={3,5,4,2,4,6};
    cout<<minPairSum(nums)<<endl;
    cout<<minPairSum(nums2);
    return 0;
}