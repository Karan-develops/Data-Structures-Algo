#include<iostream>
#include<queue>
using namespace std;
class Stack_Q{
    private:
    queue<int>q1;
    queue<int>q2;
    public:
    void push(int data){
        if(q1.empty()){
            q1.push(data);
            return;
        }
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(data);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    void pop(){
        if(q1.empty()){
            cout<<"Stack is Empty."<<endl;
            return;
        }
        return q1.pop();
    }
    int getTop(){
        if(q1.empty()){
            cout<<"Stack is Empty."<<endl;
            return -1;
        }
        return q1.front();
    }
    int getSize(){
        return q1.size();
    }
    bool isEmpty(){
        return q1.empty();
    }
};
int main(){
    Stack_Q sq;
    sq.push(10);
    sq.push(20);
    sq.push(30);
    sq.push(40);
    cout<<sq.getTop()<<endl;
    cout<<sq.getSize()<<endl;
    cout<<sq.isEmpty()<<endl;
    sq.pop();
    cout<<sq.getTop()<<endl;
    sq.pop();
    sq.pop();
    sq.pop();
    sq.pop();
    cout<<sq.getSize()<<endl;
    cout<<sq.isEmpty()<<endl;
    return 0;
}