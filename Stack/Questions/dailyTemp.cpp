// LC - 739 - Medium - Daily Temperatures
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> dailyTemperatures(vector<int>&temperatures){
    int n=temperatures.size();
    vector<int>ans(n,0);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && temperatures[st.top()]<=temperatures[i]){
            st.pop();
        }
        if(st.empty()) ans[i]=0;
        else ans[i]=st.top()-i;
        st.push(i); // Pushing Index
    }
    return ans;
}
int main(){
    // Output: [1,1,4,2,1,1,0,0]
    vector<int>temperatures={73,74,75,71,69,72,76,73};
    // Output: [1,1,1,0]
    vector<int>temperatures2={30,40,50,60};
    // Output: [1,1,0]
    vector<int>temperatures3={30,60,90};
    vector<int>ans=dailyTemperatures(temperatures);
    for(int &i:ans) cout<<i<<" ";
    return 0;
}