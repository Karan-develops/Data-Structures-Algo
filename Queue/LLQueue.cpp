#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(){
        this->data=0;
        this->next=NULL;
    }
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
class Queue{
    private:
    Node* front;
    Node* rear;
    public:
    Queue(){
        this->front=NULL;
        this->rear=NULL;
    }
    void push(int data){
        Node* newNode=new Node(data);
        if(front==NULL){
            front=newNode;
            rear=newNode;
            return;
        }
        rear->next=newNode;
        rear=newNode;
    }
    void pop(){
        if(front==NULL){
            cout<<"Queue is already Empty."<<endl;
            return;
        }
        if(front==rear){
            delete front;
            front=rear=NULL;
            return;
        }
        Node* deleteNode=front;
        front=front->next;
        delete deleteNode;
        if(front==NULL){
            rear=NULL;
        }
    }
    int getLength(){
        if(front==NULL){
            return 0;
        }
        int size=0;
        Node* temp=front;
        while(temp){
            size++;
            temp=temp->next;
        }
        return size;
    }
    int getFront(){
        if(front==NULL){
            cout<<"Queue is Empty."<<endl;
            return -1;
        }
        return front->data;
    }
    int getRear(){
        if(rear==NULL){
            cout<<"Queue is Empty."<<endl;
            return -1;
        }
        return rear->data;
    }
    bool isEmpty(){
        return front==NULL;
    }
    void printQueue(){
        if(isEmpty()){
            cout<<"Queue is Empty, Can't Print."<<endl;
            return;
        }
        Node* temp=front;
        while(temp){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    ~Queue(){
        while(!isEmpty()){
            pop();
        }
    }
};
int main(){
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.printQueue();
    return 0;
}