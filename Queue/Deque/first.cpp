#include<iostream>
using namespace std;
class Deque{
    public:
    int* arr;
    int size;
    int front;
    int rear;
    Deque(int size){
        this->size=size;
        arr=new int[size];
        front=-1;
        rear=-1;
        for(int i=0;i<size;i++){
            arr[i]=0;
        }
    }
    void push_front(int data){
        // Checking if queue has space or not
        if((front==0 && rear==size-1) || (rear+1)%size==front){
            cout<<"Queue is Full."<<endl;
            return;
        }
        // checking for first element
        if(front==-1){
            front=rear=0;
            arr[front]=data;
        } else if(front==0 && rear!=size-1){ // circular case
            front=size-1;
            arr[front]=data;
        } else{
            arr[--front]=data; // normal case
        }
    }
    void push_back(int data){
    // Check if the queue is full
    if((rear+1)%size==front){
        cout<<"Queue is Full."<<endl;
        return;
    }
    if(front==-1){
        front=rear=0;
    } else if(rear==size-1){ // circular case
        rear=0;
    } else{
        rear++;
    }
    arr[rear]=data;
}
    void pop_front(){
        if(front==-1){
            cout<<"Queue is already Empty."<<endl;
            return;
        }
        if(front==rear){
            arr[front]=-1;
            front=rear=-1;
        } else if(front==size-1){
            arr[front]=-1;
            front=0;
        } else {
            arr[front++]=-1;
        }
    }
    void pop_back(){
        if(rear==-1){
            cout<<"Queue is already Empty."<<endl;
            return;
        }
        if(front==rear){
            arr[rear]=-1;
            front=rear=-1;
        } else if(rear==0){
            arr[rear]=-1;
            rear=size-1;
        } else{
            arr[rear--]=-1;
        }
    }
    int getLength(){
        if(isEmpty()){
            return 0;
        }
        // if(front<=rear){
        //     return rear-front+1;
        // } else{
        //     return (size-front)+(rear+1);
        // }
        int len=0;
        for(int i=0;i<size;i++){
            if(arr[i]!=-1) len++;
        }
        return len;
    }
    int getFront(){
        if(isEmpty()){
            cout<<"Queue is Empty, can't retreive front Element."<<endl;
            return -1;
        }
        return arr[front];
    }
    int getBack(){
        if(isEmpty()){
            cout<<"Queue is Empty, can't retrieve rear Element."<<endl;
            return -1;
        }
        return arr[rear];
    }
    bool isEmpty(){
        return front==-1;
    }
    void printDeque(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    Deque dq(10);
    cout<<dq.getLength()<<endl;
    dq.pop_back();
    dq.pop_front();
    dq.printDeque();
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);
    dq.push_back(40);
    dq.push_back(50);
    dq.push_back(60);
    dq.push_back(70);
    dq.push_back(80);
    dq.printDeque();
    dq.pop_back();
    dq.pop_back();
    dq.printDeque();
    dq.pop_front();
    dq.printDeque();
    dq.pop_front();
    dq.pop_front();
    dq.printDeque();
    dq.push_front(101);
    dq.push_front(102);
    dq.push_front(103);
    dq.printDeque();
    dq.push_front(104);
    dq.printDeque();
    dq.pop_front();
    dq.printDeque();
    dq.pop_front();
    dq.printDeque();
    dq.push_back(201);
    dq.printDeque();
    dq.push_back(202);
    dq.push_back(203);
    dq.push_back(204);
    dq.printDeque();
    dq.push_back(205);
    dq.printDeque();
    cout<<dq.getLength()<<endl;
    dq.push_back(205);
    dq.push_back(205);
    dq.push_back(205);
    dq.printDeque();
    return 0;
}