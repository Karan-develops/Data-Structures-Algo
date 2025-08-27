// LC - 78 - Medium - Subsets
// Given an integer array nums of unique elements
#include<iostream>
#include<vector>
using namespace std;
class BackTracking{
    int n;
    void solve(vector<vector<int>>&ans,vector<int>&nums,vector<int>&temp,int i){
        if(i>=n){
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(nums[i]);
        solve(ans,nums,temp,i+1);

        temp.pop_back();
        solve(ans,nums,temp,i+1);
    }
    public:
    vector<vector<int>> subsets(vector<int>&nums){
        n=nums.size();
        vector<vector<int>>ans;
        vector<int>temp;
        
        solve(ans,nums,temp,0);
        
        return ans;
    }  
};
int main(){
    // Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
    vector<int>nums={1,2,3};
    // Output: [[],[0]]
    vector<int>nums={0};
    return 0;
}