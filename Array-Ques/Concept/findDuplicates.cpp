// LC - 442 - Medium - Find All Duplicates in an Array
#include<iostream>
#include<vector>
using namespace std;
// Using Elements as Index
vector<int> findDuplicates(vector<int>&nums){
    int n=nums.size();
    vector<int>ans;

    for(int i=0;i<n;i++){
        int num=abs(nums[i]);

        if(nums[num-1]<0) ans.push_back(num);
        else nums[num-1]*=-1;
    }
    return ans;
}
int main(){
    // Output: [2,3]
    vector<int>nums={4,3,2,7,8,2,3,1};
    // Output: [1]
    vector<int>nums2={1,1,2};
    // Output: []
    vector<int>nums3={1};
    return 0;
}