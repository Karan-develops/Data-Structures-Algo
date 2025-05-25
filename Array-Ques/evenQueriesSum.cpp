// LC - 985 - Medium - Sum of Even Numbers After Queries
#include<iostream>
#include<vector>
using namespace std;
vector<int> sumEvenAfterQueries(vector<int>&nums,vector<vector<int>>&queries){
    int n=nums.size();
    int sum=0;
    vector<int>ans;

    for(int &i:nums) if(!(i&1)) sum+=i;

    for(auto &vec:queries){
        int val=vec[0];
        int idx=vec[1];

        if(nums[idx]%2==0) sum-=nums[idx];
        nums[idx]+=val;
        if(nums[idx]%2==0) sum+=nums[idx];
        ans.push_back(sum);
    }
    return ans;
}
int main(){
    // Output: [8,6,2,4]
    vector<int>nums={1,2,3,4};
    vector<vector<int>>queries={{1,0},{-3,1},{-4,0},{2,3}};
    // Output: [0]
    vector<int>nums={1};
    vector<vector<int>>queries={{4,0}};
    return 0;
}