// LC - 503 - Medium - Next Greater Element II
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> nextGreaterElements(vector<int>&nums){
    int n=nums.size();
    vector<int>ans(n);
    stack<int>st;

    for(int i=2*n-1;i>=0;i--){
        int idx=i%n;

        while(!st.empty() && st.top()<=nums[idx]){
            st.pop();
        }
        ans[idx]=st.empty()?-1:st.top();
        st.push(nums[idx]);
    }
    return ans;
}
int main(){
    // Output: [2,-1,2]
    vector<int>nums={1,2,1};
    // Output: [2,3,4,-1,4]
    vector<int>nums2={1,2,3,4,3};
    vector<int>ans=nextGreaterElements(nums);
    for(int &i:ans) cout<<i<<" ";
    return 0;
}