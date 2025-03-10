#include<iostream>
#include<vector>
using namespace std;
void solve(vector<vector<int>>&ans,vector<int>&nums,int start,int &s){
    if(start==s){
        ans.push_back(nums);
        return;
    }
    for(int i=start;i<s;i++){
        swap(nums[i],nums[start]);
        solve(ans,nums,start+1,s);
        // Backtracking
        swap(nums[i],nums[start]);
    }
}
vector<vector<int>> permute(vector<int>&nums) {
    int s=nums.size();
    vector<vector<int>>ans;
    solve(ans,nums,0,s);
    return ans;
}
int main(){
    vector<int>nums1={1,2,3};
    vector<int>nums2={0,1};
    vector<vector<int>>ans1=permute(nums1);
    // OP - [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
    for(auto &vec:ans1){
        cout<<"[";
        for(int &i:vec) cout<<i;
        cout<<"]";
    }
    return 0;
}