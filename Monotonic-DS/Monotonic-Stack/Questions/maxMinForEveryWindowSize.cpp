// GFG - Max of min for every window size
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> maxOfMins(vector<int>&arr){
    int n=arr.size();
    vector<int>left(n),right(n);

    // Step 1: Previous smaller element
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        left[i]=st.empty()?-1:st.top();
        st.push(i);
    }

    // Step 2: Next smaller element
    st=stack<int>();
    
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        right[i]=st.empty()?n:st.top();
        st.push(i);
    }

    // Step 3: Answer array
    vector<int>ans(n+1,INT_MIN);
    for(int i=0;i<n;i++){
        // window size where arr[i] is min
        // NOTE : right & left me index store h
        int len=right[i]-left[i]-1;
        ans[len]=max(ans[len],arr[i]);
    }

    // Step 4: Fill remaining values
    for(int i=n-1;i>=1;i--){
        ans[i]=max(ans[i],ans[i+1]);
    }

    // Discard index 0 (as window sizes start from 1)
    ans.erase(begin(ans));
    
    return ans;
}
int main(){
    // Output: [70, 30, 20, 10, 10, 10, 10] 
    vector<int>arr={10,20,30,50,10,70,30};
    // Output: [30, 20, 10]
    vector<int>arr2={10,20,30};
    return 0;
}