// LC - 907 - Medium - Sum of Subarray Minimums
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution{
    int n;
    const int MOD=1e9+7;
    typedef unsigned long long ll;
    vector<int> getNSL(vector<int>&arr){
        vector<int>ans(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            if(st.empty()) ans[i]=-1;
            else{
                while(!st.empty() && arr[st.top()]>arr[i]){
                    st.pop();
                }
                ans[i]=st.empty()?-1:st.top();
            }
            // Pushing Index
            st.push(i);
        }
        return ans;
    }
    vector<int> getNSR(vector<int>&arr){
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            if(st.empty()) ans[i]=n;
            else{
                while(!st.empty() && arr[st.top()]>=arr[i]){
                    st.pop();
                }
                ans[i]=st.empty()?n:st.top();
            }
            // Pushing Index
            st.push(i);
        }
        return ans;
    }
    public:
    int sumSubarrayMins(vector<int>&arr){
        n=arr.size();
        vector<int>NSL=getNSL(arr);
        vector<int>NSR=getNSR(arr);
        int ans=0;
        for(int i=0;i<n;i++){
            ll leftSide=i-NSL[i];
            ll rightSide=NSR[i]-i;

            ll combined=leftSide*rightSide;
            ll total=combined*arr[i];

            ans=(ans+total)%MOD;
        }
        return ans;
    }
};
int main(){
    // Output: 17
    vector<int>arr={3,1,2,4};
    // Output: 444
    vector<int>arr2={11,81,94,43,3};
    Solution sol;
    cout<<sol.sumSubarrayMins(arr)<<endl;
    cout<<sol.sumSubarrayMins(arr2);
    return 0;
}