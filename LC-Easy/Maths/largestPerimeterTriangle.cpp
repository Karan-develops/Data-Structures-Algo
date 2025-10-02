// LC - 976 - Easy - Largest Perimeter Triangle
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int largestPerimeter(vector<int>&nums){
    int n=nums.size();
    
    sort(begin(nums),end(nums));
    
    for(int i=n-3;i>=0;i--){
        if(nums[i]+nums[i+1]>nums[i+2]){
            return nums[i]+nums[i+1]+nums[i+2];
        }
    }
    
    return 0;
}
int main(){
    // Output: 5
    vector<int>nums={2,1,2};
    // Output: 0
    vector<int>nums2={1,2,1,10};
    cout<<largestPerimeter(nums)<<endl;
    cout<<largestPerimeter(nums2);
    return 0;
}