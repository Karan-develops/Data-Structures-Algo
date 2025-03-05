#include<iostream>
using namespace std;
class Queue{
    private:
    int* arr;
    int front;
    int rear;
    int size;
    public:
    Queue(int size){
        this->size=size;
        arr=new int[size];
        front=0;
        rear=-1;
    }
    void push(int data){
        if(rear==size){
            cout<<"Queue is Full."<<endl;
            return;
        }
        ++rear;
        arr[rear]=data;
    }
    void pop(){
        if(front>rear){
            cout<<"Queue is already Empty."<<endl;
            return;
        }
        int poppedElement=arr[front];
        arr[front]=-1;
        front++;
        cout<<"Element: "<<poppedElement<<" is removed from the queue."<<endl;
    }
    int getFront(){
        if(front>rear){
            cout<<"Queue is Empty."<<endl;
            return -1;
        }
        return arr[front];
    }
    int getRear(){
        if(rear==-1){
            cout<<"Queue is Empty."<<endl;
            return -1;
        }
        return arr[rear];
    }
    bool isEmpty(){
        if(front>rear) return true;
        return false;
    }
    int getSize(){
        return rear-front+1;
    }
};
int main(){
    Queue q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.pop();
    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;
    cout<<q.isEmpty()<<endl;
    cout<<q.getSize()<<endl;
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    return 0;
}