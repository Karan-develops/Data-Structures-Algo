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
  ~Node(){
    this->data;
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
    if(head==NULL){
        tail=newNode;
    }
    head=newNode;
}
void insertAtTail(Node* &head,Node* &tail,int data){
    Node* newNode=new Node(data);
    if(tail==NULL){
        head=newNode;
    } else{
        tail->next=newNode;
    }
    tail=newNode;
}
void deleteHead(Node* &head){
    Node* &temp=head;
    head=head->next;
    delete temp;
}
void deleteNode(Node* &head,Node* &tail,int pos){
    if(head==NULL){
        cout<<"LL is empty"<<endl;
        return;
    }
    if(pos<0){
        cout<<"Can't Access this Location."<<endl;
        return;
    }
    if(pos==0){
        deleteHead(head);
        return;
    }
    Node* prev=head;
    int i=2;
    while(i<pos){
        prev=prev->next;
        i++;
    }
    Node* curr=prev->next;
    prev->next=curr->next;
    curr->next=NULL;
    delete curr;
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
    deleteNode(head,tail,5);
    printList(head);
    return 0;
}