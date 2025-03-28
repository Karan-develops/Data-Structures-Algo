// LC - 2780 - Medium - Minimum Index of a Valid Split
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int minimumIndex(vector<int>&nums){
    int n=nums.size();
    unordered_map<int,int>mp1; // left subArray
    unordered_map<int,int>mp2; // right subArray

    for(auto &i:nums) mp2[i]++;

    for(int i=0;i<n;i++){
        int num=nums[i];

        mp1[num]++;
        mp2[num]--;

        int n1=i+1,n2=n-i-1;

        if(mp1[num]>n1/2 && mp2[num]>n2/2) return i;
    }
    return -1;
}
int main(){
    // Output: 2
    vector<int>nums={1,2,2,2};
    // Output: 4
    vector<int>nums2={2,1,3,1,1,1,7,1,2,1};
    // Output: -1
    vector<int>nums3={3,3,3,3,7,2,2};
    cout<<minimumIndex(nums)<<endl;
    cout<<minimumIndex(nums2)<<endl;
    cout<<minimumIndex(nums3);
    return 0;
}