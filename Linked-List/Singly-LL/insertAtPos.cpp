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
};
int findLength(Node* &head){
    Node* temp=head;
    int len=0;
    while(temp!=NULL){
        temp=temp->next;
        len++;
    }
    return len;
}
void insertAtHead(Node* &head,Node* &tail,int data){
    Node* newNode=new Node(data);
    if(head==NULL){
        tail=newNode;
    }
    newNode->next=head;
    head=newNode;
}
void insertAtTail(Node* &head,Node* &tail,int data){
    Node* newNode=new Node(data);
    if(tail==NULL){
        head=newNode;
    }
    tail->next=newNode;
    tail=newNode;
}
void insertAtPos(Node* &head,Node* &tail,int data,int pos){
    if(pos<0){
        cout<<"Can't Access this location!"<<endl;
        return;
    }
    Node* newNode=new Node(data);
    if(head==NULL || tail==NULL){
        head=newNode;
        tail=newNode;
        return;
    }
    if(pos==0){
        insertAtHead(head,tail,data);
        return;
    }
    int len=findLength(head);
    if(len<pos){
        insertAtTail(head,tail,data);
        return;
    }
    Node* temp=head;
    int i=1;
    while(i<pos){
        temp=temp->next;
        i++;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}
int main(){
    Node* head=NULL;
    Node* tail=NULL;
    insertAtHead(head,tail,10);
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,30);
    insertAtHead(head,tail,40);
    insertAtTail(head,tail,50);
    insertAtTail(head,tail,60);
    insertAtTail(head,tail,70);
    insertAtTail(head,tail,80);
    printList(head);
    insertAtPos(head,tail,100,0);
    printList(head);
    insertAtPos(head,tail,200,3);
    printList(head);
    insertAtPos(head,tail,200,11);
    printList(head);
    return 0;
}