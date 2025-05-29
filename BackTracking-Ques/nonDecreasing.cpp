// LC - 491 - Medium - Non-decreasing Subsequences
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class BackTracking{ 
    int n;
    void solve(vector<vector<int>>&ans,vector<int>temp,vector<int>&nums,int idx){
        if(temp.size()>1){
            ans.push_back(temp);
        }

        unordered_set<int>st;

        for(int i=idx;i<n;i++){
            if((temp.empty() || nums[i]>=temp.back()) && st.find(nums[i])==st.end()){
                temp.push_back(nums[i]);
                solve(ans,temp,nums,i+1);
                temp.pop_back();

                st.insert(nums[i]);
            }
        }
    }
    public:
    vector<vector<int>> findSubsequences(vector<int>&nums){
        n=nums.size();
        vector<vector<int>>ans;
        vector<int>temp;

        solve(ans,temp,nums,0);
        return ans;
    }
};
int main(){
    // Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
    vector<int>nums={4,6,7,7};
    // Output: [[4,4]]
    vector<int>nums2={4,4,3,2,1};
    return 0;
}