// LC - 3423 - Easy - Maximum Difference Between Adjacent Elements in a Circular Array
#include<iostream>
#include<vector>
using namespace std;
int maxAdjacentDistance(vector<int>&nums){
    int n=nums.size();
    int ans=0;

    for(int i=1;i<n;i++){
        ans=max(ans,abs(nums[i]-nums[i-1]));
    }

    ans=max(ans,abs(nums[n-1]-nums[0]));
    return ans;
}
int main(){
    // Output: 3
    vector<int>nums={1,2,4};
    // Output: 5
    vector<int>nums2={-5,-10,-5};
    cout<<maxAdjacentDistance(nums)<<endl;
    cout<<maxAdjacentDistance(nums2);
    return 0;
}