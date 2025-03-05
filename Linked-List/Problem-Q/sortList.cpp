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
Node* findMid(Node* head){
    Node* slow=head;
    Node* fast=head->next;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
    }
    return slow;
}
Node* mergeList(Node* left,Node* right){
    Node* sortedList=new Node(-1);
    Node* sortedTail=sortedList;
    while(left && right){
        if(left->data<right->data){
            sortedTail->next=left;
            sortedTail=left;
            left=left->next;
        } else{
            sortedTail->next=right;
            sortedTail=right;
            right=right->next;
        }
    }
    if(left){
        sortedTail->next=left;
    }
    if(right){
        sortedTail->next=right;
    }
    return sortedList->next;
}
Node* sortList(Node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* midNode=findMid(head);
    Node* left=head;
    Node* right=midNode->next;
    midNode->next=NULL;
    // sort RE
    left=sortList(left);
    right=sortList(right);
    // Merge them
    return mergeList(left,right);
}
int main(){
    Node* head=NULL;
    Node* tail=NULL;
    addNewNodeAtTail(head,tail,4);
    addNewNodeAtTail(head,tail,2);
    addNewNodeAtTail(head,tail,1);
    addNewNodeAtTail(head,tail,3);
    printList(head);
    Node*ansList=sortList(head);
    printList(ansList);
    return 0;
}