// LC - 3152 - Medium - Special Array II
#include<iostream>
#include<vector>
using namespace std;
// Approach 1 - Brute Force - TLE
vector<bool> isArraySpecial(vector<int>&nums,vector<vector<int>>&queries){
    vector<bool>ans;

    for(auto &vec:queries){
        int start=vec[0];
        int end=vec[1];

        bool flag=true;
        for(int i=start;i<end;i++){
            if(!((nums[i]+nums[i+1])&1)){
                ans.push_back(false);
                flag=false;
                break;
            }
        }
        if(flag) ans.push_back(true);
    }
    return ans;
}
// Approach 2 - Prefix Sum - ACCEPTED
vector<bool> isArraySpecial2(vector<int>&nums,vector<vector<int>>&queries){
    int n=nums.size();
    vector<bool>ans;
    vector<int>prefix(n,0);
    prefix[0]=true;

    for(int i=1;i<n;i++){
        if((nums[i]+nums[i-1])&1) prefix[i]=prefix[i-1];
        // Voilating Condition.
        else prefix[i]=prefix[i-1]+1;
    }
    for(auto &vec:queries){
        int start=vec[0];
        int end=vec[1];

        if(prefix[end]-prefix[start]==0) ans.push_back(true);
        else ans.push_back(false);
    }
    return ans;
}
int main(){
    // Output: [false]
    vector<int>nums={3,4,1,2,6};
    vector<vector<int>>queries={{0,4}};
    // Output: [false,true]
    vector<int>nums2={4,3,1,6};
    vector<vector<int>>queries2={{0,2},{2,3}};
    return 0;
}