// LC - 1695 - Medium - Maximum Erasure Value
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int maximumUniqueSubarray(vector<int>&nums){
    int n=nums.size();

    unordered_set<int>st;

    int ans=0;
    int i=0,j=0;
    int sum=0;

    while(j<n){
        sum+=nums[j];

        while(st.count(nums[j])){
            st.erase(nums[i]);
            sum-=nums[i];
            i++;
        }
        
        st.insert(nums[j]);
        ans=max(ans,sum);
        j++;
    }
    return ans;
}
int main(){
    // Output: 17
    vector<int>nums={4,2,4,5,6};
    // Output: 8
    vector<int>nums2={5,2,1,2,5,2,1,2,5};
    cout<<maximumUniqueSubarray(nums)<<endl;
    cout<<maximumUniqueSubarray(nums2);
    return 0;
}