#include<iostream>
#include<stack>
using namespace std;
class Queue{
    stack<int>st1;
    stack<int>st2;
    public:
    void push(int x){
        if(st1.empty()){
            st1.push(x);
            return;
        }
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(x);
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
    }
    int pop(){
        if(st1.empty()) return -1;
        int topElement=st1.top();
        st1.pop();
        return topElement;
    }
    int peek(){
        return st1.top();
    }
    bool empty(){
        return st1.empty();
    }
};
int main(){
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    cout<<q.peek();
    return 0;
}