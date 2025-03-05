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
int getLength(Node* &head){
    Node* temp=head;
    int len=0;
    while(temp!=NULL){
        temp=temp->next;
        len++;
    }
    return len;
}
void addNewNodeAtTail(Node* &head,Node* &tail,int data){
    Node* newNode=new Node(data);
    if(head==NULL){
        head=newNode;
        tail=newNode;
        return;
    }
    tail->next=newNode;
    tail=newNode;
}
Node* rotateList(Node* head,int k){
    int lenOfList=getLength(head);
    int actualRotateK=k%lenOfList;
    int newLastNodePos=lenOfList-actualRotateK-1;
    Node* temp=head;
    while(newLastNodePos--){
        temp=temp->next;
    }
    Node* newHead=temp->next;
    temp->next=NULL;
    Node* it=newHead;
    while(it->next){
        it=it->next;
    }
    it->next=head;
    return newHead;
}
int main(){
    Node* head=NULL;
    Node* tail=NULL;
    addNewNodeAtTail(head,tail,1);
    addNewNodeAtTail(head,tail,2);
    addNewNodeAtTail(head,tail,3);
    addNewNodeAtTail(head,tail,4);
    addNewNodeAtTail(head,tail,5);
    printList(head);
    int k=2;
    Node* newrotatedList=rotateList(head,k);
    printList(newrotatedList);
    return 0;
}