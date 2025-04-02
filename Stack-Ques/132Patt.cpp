// LC - 456 - Medium - 132 Pattern
// Conditions
// i < j < k
// nums[i] < nums[k] < nums[j].
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
bool find132pattern(vector<int>&nums){
    int n=nums.size();
    stack<int>st;
    int num3=INT_MIN;
    for(int i=n-1;i>=0;i--){
        if(nums[i]<num3) return true;
        while(!st.empty() && st.top()<nums[i]){
            num3=st.top();
            st.pop();
        }
        st.push(nums[i]);
    }
    return false;
}
int main(){
    // Output: false
    vector<int>nums={1,2,3,4};
    // Output: true
    vector<int>nums2={3,1,4,2};
    // Output: true
    vector<int>nums3={-1,3,2,0};
    cout<<find132pattern(nums)<<endl;
    cout<<find132pattern(nums2)<<endl;
    cout<<find132pattern(nums3);
    return 0;
}