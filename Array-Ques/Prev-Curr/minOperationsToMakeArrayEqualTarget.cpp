// LC - 3229 - HARD - Minimum Operations to Make Array Equal to Target
// Easier Version → https://github.com/Karan-develops/Data-Structures-Algo/blob/main/Array-Ques/Concept/minNumberIncrementsSubarraysToFormTargetArray.cpp
#include<iostream>
#include<vector>
using namespace std;
long long minimumOperations(vector<int>&nums,vector<int>&target){
    int n=nums.size();

    long long ans=0;

    int prev=0,curr=0;

    for(int i=0;i<n;i++){
        curr=target[i]-nums[i];

        // Different Sign +-
        if((curr>0 && prev<0) || (curr<0 && prev>0)){
            ans+=abs(curr);
        } else if(abs(curr)>abs(prev)){
            ans+=(abs(curr-prev));
        }

        prev=curr;
    }

    return ans;
}
int main(){
    // Output: 2
    vector<int>nums={3,5,1,2},target={4,6,2,4};
    // Output: 5
    vector<int>nums2={1,3,2},target2={2,1,4};
    cout<<minimumOperations(nums,target)<<endl;
    cout<<minimumOperations(nums2,target2);
    return 0;
}