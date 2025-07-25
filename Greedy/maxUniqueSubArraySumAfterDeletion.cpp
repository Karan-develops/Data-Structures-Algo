// LC - 3487 - Easy - Maximum Unique Subarray Sum After Deletion
// Acceptance Rate - 26%
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int maxSum(vector<int>&nums){
    int ans=0;
    int mini=INT_MIN;

    unordered_set<int>st;
    
    for(int &i:nums){
        if(i>0){
            if(st.count(i)) continue;
            st.insert(i);
            ans+=i;
        } else{
            mini=max(mini,i);
        }
    }
    return ans==0?mini:ans;
}
int main(){
    // Output: 15
    vector<int>nums={1,2,3,4,5};
    // Output: 1
    vector<int>nums2={1,1,0,1,1};
    // Output: 3
    vector<int>nums3={1,2,-1,-2,1,0,-1};
    cout<<maxSum(nums)<<endl;
    cout<<maxSum(nums2)<<endl;
    cout<<maxSum(nums3);
    return 0;
}