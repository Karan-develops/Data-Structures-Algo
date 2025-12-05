// LC - 3432 - Easy - Count Partitions with Even Sum Difference
#include<iostream>
#include<vector>
using namespace std;
int countPartitions(vector<int>&nums){
    int n=nums.size();

    vector<int>prefix(n,0);
    prefix[0]=nums[0];

    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+nums[i];
    }

    int ans=0;

    for(int i=1;i<n;i++){
        int left=prefix[i];
        int right=prefix[n-1]-prefix[i];

        if(!((right-left)&1)) ans++;
    }
    return ans;
}
int main(){
    // Output: 4
    vector<int>nums={10,10,3,7,6};
    // Output: 0
    vector<int>nums2={1,2,2};
    // Output: 3
    vector<int>nums3={2,4,6,8};
    cout<<countPartitions(nums)<<endl;
    cout<<countPartitions(nums2)<<endl;
    cout<<countPartitions(nums3);
    return 0;
}