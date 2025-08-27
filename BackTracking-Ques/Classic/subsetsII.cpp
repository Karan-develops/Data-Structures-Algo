// LC - 90 - Medium - Subsets II
// Given an integer array nums that may contain duplicates
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class BackTracking{
    void solve(vector<vector<int>>&ans,vector<int>&nums,vector<int>temp,int idx){
        ans.push_back(temp);

        for(int i=idx;i<nums.size();i++){
            if(i>idx && nums[i]==nums[i-1]){
                continue;
            }

            temp.push_back(nums[i]);
            solve(ans,nums,temp,i+1);
            temp.pop_back();
        }
    }
    public:
    vector<vector<int>> subsetsWithDup(vector<int>&nums){
        vector<vector<int>>ans;
        vector<int>temp;

        // To Handle Duplicates
        sort(begin(nums),end(nums));
        
        solve(ans,nums,temp,0);

        return ans;
    }
};
int main(){
    // Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
    vector<int>nums={1,2,2};
    // Output: [[],[0]]
    vector<int>nums2={0};
    return 0;
}