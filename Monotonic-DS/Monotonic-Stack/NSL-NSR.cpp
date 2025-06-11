// Next Smaller & Larger Elements in Left-Right
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Monotonic{
    public:
    // Next Smaller Element in the left.
    void NSL(vector<int>&nums){
        int n=nums.size();
        vector<int>ans(n,-1);
        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            ans[i]=st.empty()?-1:nums[st.top()];
            // IMP** --> Pushing Index
            st.push(i);
        }

        for(int &i:ans) cout<<i<<" ";
        cout<<endl;
    }
    // Next Greater in the left.
    void NGL(vector<int>&nums){
        int n=nums.size();
        vector<int>ans(n,-1);
        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }
            ans[i]=st.empty()?-1:nums[st.top()];
            // IMP** --> Pushing Index
            st.push(i);
        }

        for(int &i:ans) cout<<i<<" ";
        cout<<endl;
    }
    // Next Smaller element in the right
    void NSR(vector<int>&nums){
        int n=nums.size();
        vector<int>ans(n,-1);
        stack<int>st;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            ans[i]=st.empty()?-1:nums[st.top()];
            // IMP** --> Pushing Index
            st.push(i);
        }

        for(int &i:ans) cout<<i<<" ";
        cout<<endl;
    }
    // Next Greater element in the right
    void NGR(vector<int>&nums){
        int n=nums.size();
        vector<int>ans(n,-1);
        stack<int>st;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }
            ans[i]=st.empty()?-1:nums[st.top()];
            // IMP** --> Pushing Index
            st.push(i);
        }

        for(int &i:ans) cout<<i<<" ";
        cout<<endl;
    }
};
int main(){
    vector<int>nums={4,2,5,1,3};

    Monotonic sol;
    sol.NSL(nums);
    sol.NGL(nums);
    sol.NSR(nums);
    sol.NGR(nums);
    return 0;
}