// Tortoise Algorithm - slow and fast pointer.
// slow = head
// fast = head->next
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
        cout<<"Node with value: "<<this->data<<" deleted."<<endl;
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
void addNodeAtTail(Node* &head,Node* &tail,int data){
    Node* newNode=new Node(data);
    if(head==NULL){
        head=newNode;
        tail=newNode;
        head->next=tail;
        return;
    }
    tail->next=newNode;
    tail=newNode;
}
// Approach One
int getLength(Node* &head){
    Node* temp=head;
    int i=1;
    while(temp!=NULL){
        temp=temp->next;
        i++;
    }
    return i/2;
}
void printMidNode(Node* &head,int index){
    if(head==NULL){
        cout<<"LL is empty."<<endl;
        return;
    }
    Node* temp=head;
    int i=1;
    while(i!=index){
        temp=temp->next;
        i++;
    }
    cout<<temp->data<<endl;
}
// Approach two
void tortoise(Node* &head){
    if(head==NULL){
        cout<<"LL is empty."<<endl;
        return;
    }
    Node* slow=head;
    Node* fast=head->next;
    while(fast->next!=NULL){
        fast=fast->next;
        if(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
    }
    cout<<slow->data<<endl;
}
int main(){
    Node* head=NULL;
    Node* tail=NULL;
    addNodeAtTail(head,tail,10);
    addNodeAtTail(head,tail,20);
    addNodeAtTail(head,tail,30);
    addNodeAtTail(head,tail,40);
    addNodeAtTail(head,tail,50);
    addNodeAtTail(head,tail,60);
    printList(head);
    // int halfLen=getLength(head);
    // printMidNode(head,halfLen);
    tortoise(head);
    return 0;
}