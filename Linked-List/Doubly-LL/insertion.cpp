#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(){
        this->data=0;
        this->prev=NULL;
        this->next=NULL;
    }
    Node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
};
void printList(Node* &head,Node* &tail){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int getLength(Node* &head){
    int len=0;
    Node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        len++;
    }
    return len;
}
void addNewNodeAtHead(Node* &head,Node* &tail,int data){
    Node* newNode=new Node(data);
    if(head==NULL){
        head=newNode;
        tail=newNode;
        return;
    }
    newNode->next=head;
    head=newNode;
}
void addNewNodeAtTail(Node* &head,Node* &tail,int data){
    Node* newNode=new Node(data);
    if(head==NULL){
        head=newNode;
        tail=newNode;
        return;
    }
    tail->next=newNode;
    newNode->prev=tail;
    tail=newNode;
}
int main(){
    Node* head=NULL;
    Node* tail=NULL;
    addNewNodeAtHead(head,tail,10);
    addNewNodeAtHead(head,tail,20);
    addNewNodeAtHead(head,tail,30);
    addNewNodeAtHead(head,tail,40);
    addNewNodeAtTail(head,tail,50);
    addNewNodeAtTail(head,tail,60);
    addNewNodeAtTail(head,tail,70);
    addNewNodeAtTail(head,tail,80);
    printList(head,tail);
    return 0;
}