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
void printList(Node* &node){
    Node* temp=node;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void insertAtHead(Node* &head,int data){
    Node* newNode=new Node(data);
    newNode->next=head;
    head=newNode;
}
int main(){
    Node* head=new Node(2);
    printList(head);
    insertAtHead(head,5);
    printList(head);
    delete head;
    return 0;
}