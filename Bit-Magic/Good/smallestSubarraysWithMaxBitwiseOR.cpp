// LC - 2411 - Medium - Smallest Subarrays With Maximum Bitwise OR
#include<iostream>
#include<vector>
using namespace std;
vector<int> smallestSubarrays(vector<int>&nums){
    int n=nums.size();

    vector<int>ans(n);
    // setBitIndex[j]=i, it means that jth bit can be set via element at index i in nums
    vector<int>setBitIndex(32,-1);

    for(int i=n-1;i>=0;i--){
        int endIndex=i;

        // nums[i]=binary representation, check all 32-bits
        for(int j=0;j<32;j++){
            //if jth bit is not set
            if(!(nums[i] & (1<<j))){
                if(setBitIndex[j]!=-1){
                    endIndex=max(endIndex,setBitIndex[j]);
                }
            }
            // store info that this number can set this bit
            else setBitIndex[j]=i;
        }
        ans[i]=endIndex-i+1;
    }
    return ans;
}
int main(){
    // Output: [3,3,2,2,1]
    vector<int>nums={1,0,2,1,3};
    // Output: [2,1]
    vector<int>nums2={1,2};
    
    vector<int>ans=smallestSubarrays(nums);

    for(int &i:ans) cout<<i<<" ";
    
    return 0;
}