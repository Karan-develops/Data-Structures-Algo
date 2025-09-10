// LC - 2239 - Easy - Find Closest Number to Zero
#include<iostream>
#include<vector>
using namespace std;
int findClosestNumber(vector<int>&nums){
    int ans=0,diff=INT_MAX;

    for(int &i:nums){
        if(abs(i)<diff){
            diff=abs(i);
            ans=i;
        } else if(abs(i)==diff){
            ans=max(ans,i);
        }
    }
    return ans;
}
int main(){
    // Output: 1
    vector<int>nums={-4,-2,1,4,8};
    // Output: 1
    vector<int>nums2={2,-1,1};
    cout<<findClosestNumber(nums)<<endl;
    cout<<findClosestNumber(nums2);
    return 0;
}