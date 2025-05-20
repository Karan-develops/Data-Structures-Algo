// LC - 3355 - Medium - Zero Array Transformation I
#include<iostream>
#include<vector>
using namespace std;
bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    int n=nums.size();
    vector<int>diff(n,0);
    for(int i=0;i<queries.size();i++){
        int l=queries[i][0];
        int r=queries[i][1];

        diff[l]+=1;
        if(r+1<n) diff[r+1]-=1;
    }
    vector<int>ans(n,0);
    int currSum=0;
    for(int i=0;i<n;i++){
        currSum+=diff[i];
        ans[i]=currSum;
    }
    for(int i=0;i<n;i++){
        if(ans[i]<nums[i]) return false;
    }
    return true;
}
int main(){
    // Output: true
    vector<int>nums={1,0,1};
    vector<vector<int>>queries={{0,2}};
    // Output: false
    vector<int>nums2={4,3,2,1};
    vector<vector<int>>queries2={{1,3},{0,2}};
    cout<<isZeroArray(nums,queries)<<endl;
    cout<<isZeroArray(nums2,queries2);
    return 0;
}