// GFG - Reverse First K elements of Queue
#include<iostream>
#include<stack>
#include<queue>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k) {
    int n=q.size();
    stack<int>st;
    for(int i=0;i<k;i++){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    for(int i=0;i<n-k;i++){
        q.push(q.front());
        q.pop();
    }
    return q;
}
int main(){
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    int k=3;
    queue<int>ans=modifyQueue(q,k);
    while(!ans.empty()){
        cout<<ans.front()<<" ";
        ans.pop();
    }
    return 0;
}