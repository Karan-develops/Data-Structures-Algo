// GFG - Next element with greater frequency
#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;
vector<int> findGreater(vector<int>&arr){
    int n=arr.size();
    vector<int>ans(n);
    
    unordered_map<int,int>mp;
    for(int &i:arr) mp[i]++;
    
    stack<int>st;
    
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && mp[arr[st.top()]]<=mp[arr[i]]){
            st.pop();
        }
        ans[i]=st.empty()?-1:arr[st.top()];
        st.push(i);
    }
    return ans;
}
int main(){
    // Output: [1, -1, -1, 2, 1, -1]
    vector<int>arr={2,1,1,3,2,1};
    // Output: [-1, 5, -1, -1, -1]
    vector<int>arr={5,1,5,6,6};
    return 0;
}