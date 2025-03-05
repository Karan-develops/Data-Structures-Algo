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
void printList(Node* &node){
    Node* temp=node;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void insertAtTail(Node* &tail,int data){
    Node* newNode=new Node(data);
    tail->next=newNode;
    tail=newNode;
}
int main(){
    Node* head=new Node(2);
    Node* tail=new Node(4);
    head->next=tail;
    printList(head);
    insertAtTail(tail,5);
    insertAtTail(tail,8);
    printList(head);
    return 0;
}