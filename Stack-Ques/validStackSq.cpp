// LC - 946 - Medium - Validate Stack Sequences
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
bool validateStackSequences(vector<int>&pushed,vector<int>&popped){
    int n=pushed.size();
    stack<int>st;
    int i=0,j=0;
    while(i<n && j<n){
        st.push(pushed[i]);
        while(!st.empty() && j<n && st.top()==popped[j]){
            st.pop();
            j++;
        }
        i++;
    }
    return st.empty();
}
int main(){
    // Output: true
    vector<int>pushed={1,2,3,4,5},popped={4,5,3,2,1};
    // Output: false
    vector<int>pushed2={1,2,3,4,5},popped2={4,3,5,1,2};
    cout<<validateStackSequences(pushed,popped)<<endl;
    cout<<validateStackSequences(pushed2,popped2);
    return 0;
}