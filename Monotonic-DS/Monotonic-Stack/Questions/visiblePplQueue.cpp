// LC - 1944 - HARD - Number of Visible People in a Queue
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> canSeePersonsCount(vector<int>&heights){
    int n=heights.size();

    stack<int>st;
    vector<int>ans(n,-1);

    for(int i=n-1;i>=0;i--){
        int count=0;
        while(!st.empty() && heights[st.top()]<heights[i]){
            st.pop();
            count++;
        }
        if(!st.empty()) count++;
        ans[i]=count;
        st.push(i);
    }
    return ans;
}
int main(){
    // Output: [3,1,2,1,1,0]
    vector<int>heights={10,6,8,5,11,9};
    // Output: [4,1,1,1,0]
    vector<int>heights2={5,1,2,3,10};
    return 0;
}