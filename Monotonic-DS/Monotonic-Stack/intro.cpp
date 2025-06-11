// Monotonic Stacks
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Monotonic_Stack{
    public:
    void monotonicIncreasing(vector<int>&nums){
        int n=nums.size();
        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            // Imp** --> Pushing Index
            st.push(i);
        }
        while(!st.empty()){
            cout<<nums[st.top()]<<" ";
            st.pop();
        }
    }
    void monotonicDecreasing(vector<int>&nums){
        int n=nums.size();
        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }
            // Imp** --> Pushing Index
            st.push(i);
        }
        while(!st.empty()){
            cout<<nums[st.top()]<<" ";
            st.pop();
        }
    }
};
int main(){
    vector<int>nums={4,2,5,1,3};

    Monotonic_Stack sol;
    sol.monotonicIncreasing(nums);
    cout<<endl;
    sol.monotonicDecreasing(nums);
    return 0;
}