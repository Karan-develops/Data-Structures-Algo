// LC - 39 - Medium - Combination Sum
#include<iostream>
#include<vector>
using namespace std;
class Solution{
    int n;
    void solve(vector<vector<int>>&ans,vector<int>&candidates,vector<int>temp,int target,int currSum,int i){
        if(currSum==target){
            ans.push_back(temp);
            return;
        }
        if(currSum>target || i>=n) return;

        temp.push_back(candidates[i]);
        solve(ans,candidates,temp,target,currSum+candidates[i],i);
        temp.pop_back();
        solve(ans,candidates,temp,target,currSum,i+1);
    }
    public:
    vector<vector<int>> combinationSum(vector<int>&candidates,int target){
        n=candidates.size();
        vector<vector<int>>ans;
        vector<int>temp;
        solve(ans,temp,candidates,target,0,0);
        return ans;
    }
};
int main(){
    // Output: [[2,2,3],[7]]
    vector<int>candidates={2,3,6,7};
    int target=7;
    // Output: [[2,2,2,2],[2,3,3],[3,5]]
    vector<int>candidates2={2,3,5};
    int target2=8;
    // Output: []
    vector<int>candidates3={2};
    int target3=1;
    return 0;
}