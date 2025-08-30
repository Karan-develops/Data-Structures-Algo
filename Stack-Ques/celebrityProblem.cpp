// GFG - The Celebrity Problem
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int celebrity(vector<vector<int>>&mat){
    int n=mat.size();
    stack<int>st;

    // push everyone into the stack
    for(int i=0;i<n;i++){
        st.push(i);
    }

    // check who is not celebrity by comparing 2 persons
    while(st.size()!=1){
        int a=st.top(); st.pop();
        int b=st.top(); st.pop();
        if(mat[a][b]){
            // a is not celebrity
            st.push(b);
        } else{
            // b is not celebrity
            st.push(a);
        }
    }

    // check if the last left person is celebrity or not
    int mightBeCelebrity=st.top(); st.pop();
    // celebrity shouldn't know anyone
    for(int j=0;j<n;j++){
        if(j==mightBeCelebrity) continue;
        if(mat[mightBeCelebrity][j]!=0){
            return -1;
        }
    }
    // everyone should know celebrity
    for(int i=0;i<n;i++){
        if(i==mightBeCelebrity) continue;
        if(mat[i][mightBeCelebrity]==0){
            return -1;
        }
    }
    return mightBeCelebrity;
}
int main(){
    // Output: 1
    vector<vector<int>>mat={{1,1,0},{0,1,0},{0,1,1}};
    // Output: -1
    vector<vector<int>>mat2={{1,1},{1,1}};
    // Output: 0
    vector<vector<int>>mat3={{1}};
    cout<<celebrity(mat)<<endl;
    cout<<celebrity(mat2)<<endl;
    cout<<celebrity(mat3);
    return 0;
}