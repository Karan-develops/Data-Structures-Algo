// Whenever we initialize with NULL head and tail
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
void printList(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void insertAtHead(Node* &head,Node* &tail,int data){
    Node* newNode=new Node(data);
    newNode->next=head;
    // First node in the linked list (LL is empty)
    if(head==NULL){
        tail=newNode;
    }
    head=newNode;
}
// IF first node in the list is tail (LL is empty)
void insertAtTail(Node* &head,Node* &tail,int data){
    Node* newNode=new Node(data);
    if(tail==NULL){
        head=newNode;
    } else{
        tail->next=newNode;
    }
    tail=newNode;
}
int main(){
    Node* head=NULL;
    Node* tail=NULL;
    printList(head);
    // Now comment any of all head/tail it will work
    insertAtHead(head,tail,10);
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,30);
    insertAtHead(head,tail,40);
    insertAtTail(head,tail,50);
    insertAtTail(head,tail,60);
    insertAtTail(head,tail,70);
    insertAtTail(head,tail,80);
    insertAtHead(head,tail,110);
    insertAtHead(head,tail,120);
    insertAtHead(head,tail,130);
    insertAtHead(head,tail,140);
    printList(head);
    return 0;
}