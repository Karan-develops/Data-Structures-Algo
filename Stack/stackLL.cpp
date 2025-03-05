#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
class Stack{
    private:
    Node* top;
    public:
    Stack(){
        this->top=NULL;
    }
    void push(int data){
        Node* newNode=new Node(data);
        newNode->next=top;
        top=newNode;
    }
    void pop(){
        if(top==NULL){
            cout<<"Stack is already Empty."<<endl;
            return;
        } else{
            Node* temp=top;
            top=top->next;
            delete temp;
        }
    }
    int peek(){
        if(top==NULL){
            cout<<"Stack is Empty."<<endl;
            return -1;
        } else{
            return top->data;
        }
    }
    int getLength(){
        int len=0;
        Node* temp=top;
        while(temp){
            temp=temp->next;
            len++;
        }
        return len;
    }
    bool isEmpty(){
        if(top==NULL){
            return true;
        }
        return false;
    }
};
int main(){
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    cout<<"Size: "<<st.getLength()<<endl;
    cout<<"Empty?: "<<st.isEmpty()<<endl;
    while(!st.isEmpty()){
        cout<<st.peek()<<" ";
        st.pop();
    }
    cout<<endl;
    cout<<"Size: "<<st.getLength()<<endl;
    cout<<"Empty?: "<<st.isEmpty()<<endl;
    return 0;
}