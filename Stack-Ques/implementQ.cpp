// LC - 232 - Easy - Implement Queue using Stacks
// Amortized Complexity - Means not always O(n)
#include<iostream>
#include<stack>
using namespace std;
class Queue{
    public:
    stack<int>input,output;
    int peekElement=-1;
    Queue(){}
    // O(1)
    void push(int x){
        if(input.empty()){
            peekElement=x;
        }
        input.push(x);
    }
    // Amortized O(1)
    int pop(){
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        int topElement=output.top();
        output.pop();
        return topElement;
    }
    int top(){
        if(output.empty()){
            return peekElement;
        }
        return output.top();
    }
    bool isEmpty(){
        if(input.empty() && output.empty()){
            return true;
        }
        return false;
    }
};
int main(){
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout<<q.top()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.top();
    return 0;
}