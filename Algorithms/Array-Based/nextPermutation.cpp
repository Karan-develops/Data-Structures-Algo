// LC - 31 - Medium - Next Permutation
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void nextPermutation(vector<int>&nums){
    int n=nums.size();

    int idx=-1;
    for(int i=n-1;i>0;i--){
        if(nums[i]>nums[i-1]){
            idx=i-1;
            break;
        }
    }
    if(idx!=-1){
        int swapIdx=idx;
        // Need number just greater than nums[idx]
        for(int i=n-1;i>=idx+1;i--){
            if(nums[i]>nums[idx]){
                swapIdx=i;
                break;
            }
        }
        // Swap them
        swap(nums[idx],nums[swapIdx]);
    }
    reverse(begin(nums)+idx+1,end(nums));
}
int main(){
    // Output: [1,3,2]
    vector<int>nums={1,2,3};
    // Output: [1,2,3]
    vector<int>nums2={3,2,1};
    // Output: [1,5,1]
    vector<int>nums3={1,1,5};

    nextPermutation(nums);
    for(int &i:nums) cout<<i<<" ";
    return 0;
}