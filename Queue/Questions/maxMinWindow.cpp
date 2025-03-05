// **VI**
#include<iostream>
#include<deque>
#include<vector>
using namespace std;
int getMinMaxSum(vector<int>v,int k){
    int size=v.size();
    deque<int>dq1,dq2; // dq1 will store max elements , dq2 min elements
    int ans=0;
    // process first window
    for(int i=0;i<k;i++){
        while(!dq1.empty() && v[i]>=v[dq1.back()]){
            dq1.pop_back();
        }
        while(!dq2.empty() && v[i]<=v[dq2.back()]){
            dq2.pop_back();
        }
        dq1.push_back(i);
        dq2.push_back(i);
    }
    // store ans of first window
    ans+=v[dq1.front()]+v[dq2.front()];
    // process remaining windows
    for(int i=k;i<size;i++){
        // remove out of window elements from dq1 and dq2
        while(!dq1.empty() && i-dq1.front()>=k){
            dq1.pop_front();
        }
        while(!dq2.empty() && i-dq2.front()>=k){
            dq2.pop_front();
        }
        // remove smaller elements from dq1
        while(!dq1.empty() && v[i]>=v[dq1.back()]){
            dq1.pop_back();
        }
        // remove larger elements from dq2
        while(!dq2.empty() && v[i]<=v[dq2.back()]){
            dq2.pop_back();
        }
        // inserting index in dq1 and dq2
        dq1.push_back(i);
        dq2.push_back(i);
        ans+=v[dq1.front()]+v[dq2.front()];
    }
    return ans;
}
int main(){
    vector<int>v{2,5,-1,7,-3,-2,-1};
    cout<<getMinMaxSum(v,4);
    return 0;
}