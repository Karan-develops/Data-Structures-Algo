// Two methods - Reverse the list and compare. S.C -> o(n)
// S.C -> O(1) Approach
// 1) Find middle node
// 2) reverse the list after the middle node
// 3) put ptr at starting of LL and other at middle-next node.
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
        head->next=tail;
        return;
    }
    tail->next=newNode;
    tail=newNode;
}
Node* revList(Node* &head){
    Node* prevNode=NULL;
    Node* currNode=head;
    while(currNode!=NULL){
        Node* nextNode=currNode->next;
        currNode->next=prevNode;
        prevNode=currNode;
        currNode=nextNode;
    }
    return prevNode;
}
// Method - 1
bool isPalindromeByReverse(Node* &head){
    Node* prevNode=revList(head);
    Node* temp1=head;
    Node* temp2=prevNode;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data == temp2->data){
            temp1=temp1->next;
            temp2=temp2->next;
        } else{
            return false;
        }
    }
    return true;
}
// Method - 2
bool isPalindromeByMid(Node* &head){
    if(head==NULL){
        cout<<"LL is empty."<<endl;
        return false;
    }
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
    }
    Node* firstNodeOfRev=revList(slow->next);
    Node* start=head;
    while(start!=slow && firstNodeOfRev!=NULL){
        if(start->data==firstNodeOfRev->data){
            start=start->next;
            firstNodeOfRev=firstNodeOfRev->next;
        } else{
            return false;
        }
    }
    return true;
}
int main(){
    Node* head=NULL;
    Node* tail=NULL;
    addNewNodeAtTail(head,tail,10);
    addNewNodeAtTail(head,tail,20);
    addNewNodeAtTail(head,tail,30);
    addNewNodeAtTail(head,tail,30);
    addNewNodeAtTail(head,tail,20);
    addNewNodeAtTail(head,tail,10);
    printList(head);
    if(isPalindromeByMid(head)){
        cout<<"LL is Palindrome."<<endl;
    } else{
        cout<<"LL is not Palindrome."<<endl;
    }
    return 0; 
}