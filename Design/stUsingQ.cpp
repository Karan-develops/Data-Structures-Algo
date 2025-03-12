// LC - 225 - Easy
#include<iostream>
#include<queue>
using namespace std;
class Stack{
    queue<int>q;
    public:
    void push(int x){
        q.push(x);
        for(int i=0;i<q.size()-1;i++){
            q.push(q.front());
            q.pop();
        }
    }
    int pop(){
        int top=q.front();
        q.pop();
        return top;
    }
    int top(){
        return q.front();
    }
    bool empty(){
        return q.empty();
    }
};
int main(){
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    cout<<st.top();
    return 0;
}