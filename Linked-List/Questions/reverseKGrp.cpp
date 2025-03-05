// *Very Important*
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
    int len=0;
    Node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        len++;
    }
    return len;
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
Node* reverseKGrp(Node* &head,int k){
    if(head==NULL){
        cout<<"LL is empty."<<endl;
        return NULL;
    }
    int lenOfList=getLength(head);
    if(k>lenOfList){
        cout<<"LL is small for this value of k."<<endl;
        return head;
    }
    Node* prevNode=NULL;
    Node* currNode=head;
    Node* nextNode=currNode->next;
    int i=0;
    while(i<k){
        nextNode=currNode->next;
        currNode->next=prevNode;
        prevNode=currNode;
        currNode=nextNode;
        i++;
    }
    if(nextNode!=NULL){
        // We still have nodes left to reverse
        // nextNode pass kiya - *IMP*
        head->next=reverseKGrp(nextNode,k);
    }
    return prevNode;
}
int main(){
    Node* head=NULL;
    Node* tail=NULL;
    int k=3;
    addNodeAtTail(head,tail,10);
    addNodeAtTail(head,tail,20);
    addNodeAtTail(head,tail,30);
    addNodeAtTail(head,tail,40);
    addNodeAtTail(head,tail,50);
    addNodeAtTail(head,tail,60);
    printList(head);
    Node* ans=reverseKGrp(head,k);
    printList(ans);
    return 0;
}