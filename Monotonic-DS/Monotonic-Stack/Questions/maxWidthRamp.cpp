// LC - 962 - Medium - Maximum Width Ramp
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int maxWidthRamp(vector<int>&nums){
    int n=nums.size();
    stack<int>st;

    int ans=0;

    for(int i=0;i<n;i++){
        if(st.empty() || nums[st.top()]>nums[i]) st.push(i);
    }
    
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && nums[i]>=nums[st.top()]){
            ans=max(ans,i-st.top());
            st.pop();
        }
    }
    return ans;
}
int main(){
    // Output: 4
    vector<int>nums={6,0,8,2,1,5};
    // Output: 7
    vector<int>nums2={9,8,1,0,1,9,4,0,4,1};
    cout<<maxWidthRamp(nums)<<endl;
    cout<<maxWidthRamp(nums2);
    return 0;
}