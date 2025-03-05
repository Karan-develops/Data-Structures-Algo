#include<iostream>
using namespace std;
class Stack{
    private:
    int* arr;
    int top;
    int size;
    public:
    Stack(int size){
        arr=new int[size];
        this->size=size;
        this->top=-1;
    }
    void push(int data){
        if(size-top>1){
            top++;
            arr[top]=data;
        } else{
            cout<<"Stack Overflow."<<endl;
        }
    }
    void pop(){
        if(top==-1){
            cout<<"Stack is already Empty."<<endl;
        } else{
            arr[top]=0;
            top--;
        }
    }
    int getTop(){
        if(top==-1){
            cout<<"Stack is Empty.";
            return 0;
        } else{
            return arr[top];
        }
    }
    int getSize(){
        if(top==-1){
            return 0;
        } else{
            return top+1;
        }
    }
    bool isEmpty(){
        if(top==-1){
            return true;
        } else{
            return false;
        }
    }
};
int main(){
    Stack s(10);
    // insertion
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    while(!s.isEmpty()){
        cout<<s.getTop()<<" ";
        s.pop();
    }
    cout<<endl;
    cout<<"Size: "<<s.getSize()<<endl;
    
    return 0;
}