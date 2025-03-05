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
void printList(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int getLength(Node* &head){
    int len;
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
    newNode->prev=tail;
    tail->next=newNode;
    tail=newNode;
}
void addNewNodeAtPos(Node* &head,Node* &tail,int data,int pos){
    if(pos<0){
        cout<<"Can't Access this Location"<<endl;
        return;
    }
    if(pos==0){
        addNewNodeAtHead(head,tail,data);
        return;
    }
    Node* newNode=new Node(data);
    if(head==NULL){
        head=newNode;
        tail=newNode;
        return;
    }
    int lenOfList=getLength(head);
    if(pos>lenOfList){
        addNewNodeAtTail(head,tail,data);
        return;
    }
    int i=1;
    Node* temp=head;
    while(pos>i){
        temp=temp->next;
        i++;
    }
    // We can also take a current node to represent temp->next as (currNode).
    // If we take currNode then below code's order  doesn't matter.
    // But in this case without currNode order matters.
    newNode->next=temp->next;
    newNode->prev=temp;
    temp->next=newNode;
    temp->next->prev=newNode;
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
    addNewNodeAtPos(head,tail,100,5);
    printList(head);
    return 0;
}