#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int celebrity(vector<vector<int>>&v){
    int n=v.size();
    stack<int>st;
    // push everyone in stack
    for(int i=0;i<n;i++){
        st.push(i);
    }
    // check who is not celebrity by comparing two persons until one person is left
    while(st.size()!=1){
        int a=st.top(); st.pop();
        int b=st.top(); st.pop();
        // check if A know B
        if(v[a][b]){
            // if this is true means A is not celebrity
            st.push(b);
        } else{
            // B is not celebrity
            st.push(a);
        }
    }
    // check if the last left person is celebrity or not
    int mightBeCelebrity=st.top(); st.pop();
    // celebrity shouldn't know anyone means its all colums should be 0 (or whole row should be 0)
    for(int j=0;j<n;j++){
        if(v[mightBeCelebrity][j]==1) return -1;
    }
    // check if everyone knows celebrity
    for(int i=0;i<n;i++){
        // continue because of course celebrity knows himself
        if(i==mightBeCelebrity) continue;
        if(v[i][mightBeCelebrity]==0) return -1;
    }
    return mightBeCelebrity;
}
int main(){
    vector<vector<int>>matrix{{0,1,0},{0,0,0},{0,1,0}};
    // returns -1 if there is no celebrity.
    cout<<celebrity(matrix);
    return 0;
}