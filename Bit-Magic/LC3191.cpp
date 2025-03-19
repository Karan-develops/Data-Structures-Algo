// LC - 3191 - Medium - Minimum Operations to Make Binary Array Elements Equal to One I
#include<iostream>
#include<vector>
using namespace std;
int minOperations(vector<int>&nums){
    int n=nums.size();
    int ans=0;
    for(int i=0;i<n;i++){
        if(nums[i]==0){
            if(i+2>=n) return -1;
            nums[i+1]^=1;
            nums[i+2]^=1;
            ans++;
        }
    }
    return ans;
}
int main(){
    // OP - 3
    vector<int>nums1={0,1,1,1,0,0};
    // OP - -1
    vector<int>nums2={0,1,1,1};
    cout<<minOperations(nums1)<<endl;
    cout<<minOperations(nums2);
    return 0;
}