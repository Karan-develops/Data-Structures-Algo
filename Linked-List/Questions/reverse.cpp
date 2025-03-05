// Recursion/Iteration
// **IMP**
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
void addNodeAtLeft(Node* &head,Node* &tail,int data){
    Node* newNode=new Node(data);
    if(head==NULL){
        head=newNode;
        tail=newNode;
        head->next=tail;
        return;
    }
    newNode->next=head;
    head=newNode;
}
void addNodeAtRight(Node* &head,Node* &tail,int data){
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
// Recursive
Node* revList(Node* &prevNode,Node* &currNode){
    // Base Case
    if(currNode==NULL){
        return prevNode;
    }
    Node* nextNode=currNode->next;
    currNode->next=prevNode;
    // prevNode=currNode;
    // currNode=nextNode;
    // return revList(prevNode,currNode);
    return revList(currNode,nextNode);
}
int main(){
    Node* head=NULL;
    Node* tail=NULL;
    addNodeAtLeft(head,tail,10);
    addNodeAtLeft(head,tail,20);
    addNodeAtRight(head,tail,30);
    addNodeAtRight(head,tail,40);
    printList(head);
    Node* prevNode=NULL;
    Node* currNode=head;
    head=revList(prevNode,currNode);
    printList(head);
    // Iterative Approach
    Node* backwardNode=NULL;
    Node* middleNode=head;
    while(middleNode!=NULL){
        Node* forwardNode=middleNode->next;
        middleNode->next=backwardNode;
        backwardNode=middleNode;
        middleNode=forwardNode;
    }
    printList(backwardNode);
    return 0;
}