// 3 Approaches - 1 pointer / slow-fast pointer / map.
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
    tail->next=head;
}
bool isCircularWithOnePointer(Node* &head){
    if(head->next==NULL){
        cout<<"LL contains only 1 node"<<endl;
        return false;
    }
    Node* temp=head;
    while(temp!=NULL){
        if(temp->next==head){
            return true;
        }
        temp=temp->next;
    }
    return false;
}
bool isCircularWithSlowFast(Node* &head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        if(slow==fast){
            return true;
        }
    }
    return false;
}
bool isCircularWithMap(Node* &head){
    // Same as method1 just use STL Data Structures like map,set
    return true;
}
int main(){
    Node* head=NULL;
    Node* tail=NULL;
    addNodeAtTail(head,tail,10);
    addNodeAtTail(head,tail,20);
    addNodeAtTail(head,tail,30);
    addNodeAtTail(head,tail,40);
    if(isCircularWithOnePointer(head)){
        cout<<"Circular"<<endl;
    } else{
        cout<<"Not circular"<<endl;
    }
    return 0;
}