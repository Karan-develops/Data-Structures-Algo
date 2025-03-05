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
    ~Node(){
        cout<<"Node of value: "<<this->data<<" deleted."<<endl;
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
    newNode->prev=tail;
    tail->next=newNode;
    tail=newNode;
}
void addNewNodeAtPos(Node* &head,Node* &tail,int data,int pos){
    Node* newNode=new Node(data);
    if(pos<0){
        cout<<"Can't Access this Location."<<endl;
        return;
    }
    if(pos==0){
        addNewNodeAtHead(head,tail,data);
        return;
    }
    int lenOfList=getLength(head);
    if(pos>=lenOfList){
        addNewNodeAtTail(head,tail,data);
        return;
    }
    Node* prevNode=head;
    int i=1;
    while(i<pos){
        prevNode=prevNode->next;
        i++;
    }
    Node* currNode=prevNode->next;
    newNode->prev=prevNode;
    newNode->next=currNode;
    prevNode->next=newNode;
    currNode->prev=newNode;
}
void deleteHeadNode(Node* &head){
    if(head==NULL){
        cout<<"LL is empty"<<endl;
        return;
    }
    if(head->next==NULL){
        head=NULL;
    }
    Node* temp=head;
    head=head->next;
    head->prev=NULL;
    temp->next=NULL;
    delete temp;
}
void deleteTailNode(Node* &tail){
    if(tail==NULL){
        cout<<"LL is empty"<<endl;
        return;
    }
    if(tail->prev==NULL){
        tail=NULL;
        return;
    }
    Node* temp=tail;
    tail=tail->prev;
    tail->next=NULL;
    temp->prev=NULL;
    delete temp;
}
void deleteNodeAtPos(Node* &head,Node* &tail,int pos){
    if(head==NULL){
        cout<<"LL is empty"<<endl;
        return;
    }
    if(head->next==NULL){
        Node* temp=head;
        head=NULL;
        tail=NULL;
        delete temp;
    }
    if(pos<0){
        cout<<"Can't Access this Location"<<endl;
        return;
    }
    if(pos==0){
        deleteHeadNode(head);
        return;
    }
    int lenOfList=getLength(head);
    if(pos>=lenOfList){
        deleteTailNode(tail);
        return;
    }
    Node* prevNode=head;
    int i=1;
    while(pos>i){
        prevNode=prevNode->next;
        i++;
    }
    Node* currNode=prevNode->next;
    Node* nextNode=currNode->next;
    prevNode->next=nextNode;
    nextNode->prev=prevNode;
    currNode->prev=NULL;
    currNode->next=NULL;
    delete currNode;
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
    deleteHeadNode(head);
    printList(head);
    deleteTailNode(tail);
    printList(head);
    deleteNodeAtPos(head,tail,2);
    printList(head);
    return 0;
}