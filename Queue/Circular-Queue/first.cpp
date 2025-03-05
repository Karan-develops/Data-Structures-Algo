// Follow Deque code
#include<iostream>
using namespace std;
class CQueue{
    private:
    int* arr;
    int size;
    int front;
    int rear;
    public:
    CQueue(int size){
        this->size=size;
        arr=new int[size];
        front=-1;
        rear=-1;
    }
    void push(int data){
        // handling single element.
        if(front==-1 && rear==-1){
            arr[0]=data;
            front=rear=0;
            return;
        }
        if(rear==size-1 && front!=0){ // handling circular nature.
            rear=0;
            arr[0]=data;
        } else if(rear==size-1 && front==0){
            cout<<"Queue is Full."<<endl;
            return;
        } else if(rear+1==front){
            cout<<"Queue is Full."<<endl;
            return;
        } else{
            arr[rear++]=data;
        }
    }
    void pop(){
        if(front==-1){
            cout<<"Queue is already Empty."<<endl;
            return;
        }
        // handling single element
        if(front==rear){
            arr[front]=-1;
            front=rear=-1;
            return;
        }
        // circular
        if(front==size && rear<front){
            front=0;
            arr[front]=-1;
            front++;
            return;
        }
        arr[front++]=-1;
    }
    int getFront(){
        if(front==-1){
            cout<<"Queue is Empty."<<endl;
            return -1;
        }
        return arr[front];
    }
    bool isEmpty(){
        return front==-1;
    }
    void printCQueue(){
        if(front==-1){
            cout<<"Queue is Empty."<<endl;
            return;
        }
        int temp=front;
        while(true){
            cout<<arr[temp++]<<" ";
            if(temp==rear) break;
            temp=(temp+1)%size;
        }
        cout<<endl;
    }
};
int main(){
    CQueue q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    cout<<q.getFront()<<endl;
    q.printCQueue();
    cout<<q.getFront()<<endl;
    return 0;
}