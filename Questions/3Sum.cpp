#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
vector<vector<int>>ans;
void twoSum(vector<int>&nums,int target,int i){
    int j=n-1;
    while(i<j){
        int sum=nums[i]+nums[j];
        if(sum<target) i++;
        else if(sum>target) j--;
        else{
            ans.push_back({-target,nums[i],nums[j]});
            while(i<j && nums[i]==nums[i+1]) i++;
            while(i<j && nums[j]==nums[j-1]) j--;
            i++,j--;
        }
    }
}
vector<vector<int>> threeSum(vector<int>& nums) {
    n=nums.size();
    if(n<3) return {};
    sort(nums.begin(),nums.end());
    for(int i=0;i<n-2;i++){
        if(i!=0 && nums[i]==nums[i-1]) continue;
        twoSum(nums,-nums[i],i+1);
    }
    return ans;
}
int main(){
    vector<int>nums={-1,0,1,2,-1,-4};
    vector<vector<int>>ans=threeSum(nums);
    for(auto &vec:ans){
        cout<<"[";
        for(int &i:vec) cout<<i<<" ";
        cout<<"]";
    }
    return 0;
}