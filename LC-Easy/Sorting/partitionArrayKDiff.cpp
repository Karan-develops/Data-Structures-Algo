// LC - 2294 - Medium - Partition Array Such That Maximum Difference Is K
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int partitionArray(vector<int>&nums,int k){
    int n=nums.size();

    sort(begin(nums),end(nums));

    int ans=1;
    int minVal=nums[0];

    for(int i=1;i<n;i++){
        if(nums[i]-minVal>k){
            ans++;
            minVal=nums[i];
        }
    }
    return ans;
}
int main(){
    // Output: 2
    vector<int>nums={3,6,1,2,5};
    int k=2;
    // Output: 2
    vector<int>nums2={1,2,3};
    int k2=1;
    // Output: 3
    vector<int>nums3={2,2,4,5};
    int k3=0;
    cout<<partitionArray(nums,k)<<endl;
    cout<<partitionArray(nums2,k2)<<endl;
    cout<<partitionArray(nums3,k3);
    return 0;
}