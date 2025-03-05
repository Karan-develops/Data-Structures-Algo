#include<iostream>
#include<stack>
using namespace std;
class Q_Stack{
    private:
    stack<int>st1;
    stack<int>st2;
    public:
    void push(int data){
        if(st1.empty()){
            st1.push(data);
            return;
        }
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(data);
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
    }
    void pop(){
        if(st1.empty()){
            cout<<"Queue is Empty."<<endl;
            return;
        }
        st1.pop();
    }
    int getFront(){
        if(isEmpty()){
            cout<<"Queue is Empty."<<endl;
            return -1;
        }
        return st1.top();
    }
    int getSize(){
        return st1.size();
    }
    bool isEmpty(){
        return st1.empty();
    }
};
int main(){
    Q_Stack qt;
    qt.push(10);
    qt.push(20);
    qt.push(30);
    cout<<qt.isEmpty()<<endl;
    cout<<qt.getFront()<<endl;
    cout<<qt.getSize()<<endl;
    qt.pop();
    cout<<qt.getFront()<<endl;
    qt.pop();
    qt.pop();
    qt.pop();
    cout<<qt.isEmpty()<<endl;
    cout<<qt.getSize()<<endl;
}
// either push will be heavy or pop and getFront. Use based on requirement.