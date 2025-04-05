// LC - 1863 - Easy - Sum of All Subset XOR Totals
// 3 Approaches
#include<iostream>
#include<vector>
using namespace std;
class RecBack{
    void solve(vector<int>&nums,vector<vector<int>>&allSubsets,vector<int>&currSet,int i){
        if(i>=nums.size()){
            allSubsets.push_back(currSet);
            return;
        }
        currSet.push_back(nums[i]);
        solve(nums,allSubsets,currSet,i+1);
        currSet.pop_back();
        solve(nums,allSubsets,currSet,i+1);
    }
    public:
    int subsetXORSum(vector<int>&nums){
        vector<vector<int>>allSubsets;
        vector<int>currSet;
        solve(nums,allSubsets,currSet,0);
        int ans=0;
        for(auto &vec:allSubsets){
            int XOR=0;
            for(int &i:vec){
                XOR^=i;
            }
            ans+=XOR;
        }
        return ans;
    }
};
class CleanRecBack{
    int solve(vector<int>&nums,int ans,int i){
        if(i>=nums.size()) return ans;

        int include=solve(nums,nums[i]^ans,i+1);
        int exclude=solve(nums,ans,i+1);

        return include+exclude;
    }
    public:
    int subsetXORSum(vector<int>&nums){
        return solve(nums,0,0);
    }
};
class BitMagic{
    public:
    int subsetXORSum(vector<int>&nums){
        int n=nums.size();
        int ans=0;
        for(int &i:nums){
            ans|=i;
        }
        return ans<<(n-1);
    }
};
int main(){
    // Output: 6
    vector<int>nums={1,3};
    // Output: 28
    vector<int>nums2={5,1,6};
    // Output: 480
    vector<int>nums3={3,4,5,6,7,8};
    BitMagic obj;
    cout<<obj.subsetXORSum(nums)<<endl;
    cout<<obj.subsetXORSum(nums2)<<endl;
    cout<<obj.subsetXORSum(nums3);
    return 0;
}