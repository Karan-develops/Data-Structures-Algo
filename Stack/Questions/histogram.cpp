#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> prevSmaller(vector<int>&h){
    int s=h.size();
    vector<int>prev(s);
    stack<int>st;
    st.push(-1);
    for(int i=0;i<s;i++){
        // h[st.top()] because we are comparing and storing indices not values
        while(st.top()!=-1 && h[i]<=h[st.top()]){
            st.pop();
        }
        prev[i]=st.top();
        st.push(i);
    }
    return prev;
}
vector<int> nextSmaller(vector<int>&h){
    int s=h.size();
    vector<int>next(s);
    stack<int>st;
    st.push(-1);
    for(int i=s-1;i>=0;i--){
        while(st.top()!=-1 && h[i]<=h[st.top()]){
            st.pop();
        }
        if(st.top()==-1){
            next[i]=s;
        } else{
            next[i]=st.top();
        }
        st.push(i);
    }
    return next;
}
int main(){
    vector<int>heights{2,4};
    int s=heights.size();
    int maxArea=0;
    vector<int>prev=prevSmaller(heights);
    vector<int>next=nextSmaller(heights);
    for(int i=0;i<s;i++){
        int h=heights[i];
        int w=next[i]-prev[i]-1;
        maxArea=max(maxArea,h*w);
    }
    cout<<maxArea;
    return 0;
}