// LC - 78 - Medium - Subsets
#include<iostream>
#include<vector>
using namespace std;
class Solution{
    int n;
    vector<vector<int>>ans;
    void solve(vector<int>&nums,vector<int>&temp,int i){
        if(i>=n){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(nums,temp,i+1);

        temp.pop_back();
        solve(nums,temp,i+1);
    }
    public:
    vector<vector<int>> subset(vector<int>&nums){
        n=nums.size();
        vector<int>temp;
        solve(nums,temp,0);
        return ans;
    }
};
int main(){
    // OP - [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
    vector<int>nums1={1,2,3};
    // OP - [[],[0]]
    vector<int>nums2={0};
    Solution sol;
    vector<vector<int>>ans=sol.subset(nums1);
    for(auto &vec:ans){
        cout<<"[";
        for(int &i:vec) cout<<i<<" ";
        cout<<"]";
    }
}