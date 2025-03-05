// used in histogram.
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void nextSmallerElement(vector<int>&v){
    vector<int>ans(v.size());
    stack<int>st;
    st.push(-1);
    int s=v.size()-1;
    for(int i=s;i>=0;i--){
        while(v[i]<=st.top()){
            st.pop();
        }
        ans[i]=st.top();
        st.push(v[i]);
    }
    cout<<"Next: ";
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
}
void prevSmallerElement(vector<int>&v){
    vector<int>ans(v.size());
    stack<int>st;
    st.push(-1);
    for(int i=0;i<v.size();i++){
        while(v[i]<=st.top()){
            st.pop();
        }
        ans[i]=st.top();
        st.push(v[i]);
    }
    cout<<"Prev: ";
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int>v{2,1,4,3};
    vector<int>ans;
    nextSmallerElement(v);
    prevSmallerElement(v);
    return 0;
}