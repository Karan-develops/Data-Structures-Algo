// LC - 3397 - Medium - Maximum Number of Distinct Elements After Operations
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxDistinctElements(vector<int>&nums,int k){
    int n=nums.size();

    sort(begin(nums),end(nums));

    int ans=0;
    int prev=INT_MIN;

    for(int i=0;i<n;i++){
        int minVal=nums[i]-k;

        if(prev<minVal){
            //nums[i] = nums[i]-k;
            prev=minVal;
            ans++;
        } else if(prev<nums[i]+k){
            //nums[i] = prev+1;
            prev=prev+1;
            ans++;
        }
    }
    return ans;
}
int main(){
    // Output: 6
    vector<int>nums={1,2,2,3,3,4};
    int k=2;
    // Output: 3
    vector<int>nums2={4,4,4,4};
    int k2=1;
    cout<<maxDistinctElements(nums,k)<<endl;
    cout<<maxDistinctElements(nums2,k2);
    return 0;
}