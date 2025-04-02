// LC - 2873 - Easy - Maximum Value of an Ordered Triplet I
// 3 Approaches
#include<iostream>
#include<vector>
using namespace std;
long long maximumTripletValue(vector<int>& nums) {
    int n=nums.size();
    long long ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                ans=max(ans,(long long)(nums[i]-nums[j])*nums[k]);
            }
        }
    }
    return ans;
}long long maximumTripletValue(vector<int>& nums) {
    int n=nums.size();
    vector<int>leftMax(n);
    vector<int>rightMax(n);
    for(int i=1;i<n;i++){
        leftMax[i]=max(leftMax[i-1],nums[i-1]);
    }
    for(int i=n-2;i>=0;i--){
        rightMax[i]=max(rightMax[i+1],nums[i+1]);
    }
    long long ans=0;
    for(int i=1;i<n-1;i++){
        ans=max(ans,(long long)(leftMax[i]-nums[i])*rightMax[i]);
    }
    return ans;
}
long long maximumTripletValue(vector<int>& nums) {
    int n=nums.size();
    long long maxDiff=0,max_i=0,ans=0;

    for(int i=0;i<n;i++){
        ans=max(ans,maxDiff*nums[i]);
        maxDiff=max(maxDiff,max_i-nums[i]);
        max_i=max(max_i,(long long)nums[i]);
    }
    return ans;
}
int main(){
    // Output: 77
    vector<int>nums={12,6,1,2,7};
    // Output: 133
    vector<int>nums={1,10,3,4,19};
    // Output: 0
    vector<int>nums={1,2,3};
    return 0;
}