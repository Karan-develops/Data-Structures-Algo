// LC - 3542 - Medium - Minimum Operations to Convert All Elements to Zero
// 2 Approaches
#include<iostream>
#include<vector>
#include<unordered_set>
#include<stack>
using namespace std;
// Approach 1 - Brute Force
int minOperationsBruteForce(vector<int>&nums){
    int n=nums.size();
    
    unordered_set<int>st(begin(nums),end(nums));
    int ans=0;

    for(int target:st){
        if(target==0) continue;
        
        bool flow=false;
        
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                if(!flow){
                    flow=true;
                    ans++;
                }
            } else if(nums[i]<target){
                flow=false;
            }
        }
    }
    return ans;
}
// Approach 2 - Monotonic Stack
int minOperations(vector<int>&nums){
    int n=nums.size();
    stack<int>st;

    int ans=0;

    for(int i=0;i<n;i++){
        while(!st.empty() && st.top()>nums[i]){
            st.pop();
        }

        if(nums[i]==0) continue;
        
        if(st.empty() || st.top()<nums[i]){
            st.push(nums[i]);
            ans++;
        }
    }

    return ans;
}
int main(){
    // Output: 1
    vector<int>nums={0,2};
    // Output: 3
    vector<int>nums2={3,1,2,1};
    // Output: 4
    vector<int>nums3={1,2,1,2,1,2};
    cout<<minOperations(nums)<<endl;
    cout<<minOperations(nums2)<<endl;
    cout<<minOperations(nums3);
    return 0;
}