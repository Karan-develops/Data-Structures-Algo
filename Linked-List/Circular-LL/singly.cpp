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
void printList(Node* &head,Node* &tail){
    Node* temp=head->next;
    cout<<head->data<<" ";
    while(temp!=head){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void addNewNode(Node* &head,Node* &tail,int data){
    Node* newNode=new Node(data);
    if(head==NULL){
        head=newNode;
        tail=newNode;
        return;
    }
    tail->next=newNode;
    tail=newNode;
    tail->next=head;
}
int main(){
    Node* head=NULL;
    Node* tail=NULL;
    addNewNode(head,tail,10);
    addNewNode(head,tail,20);
    addNewNode(head,tail,30);
    addNewNode(head,tail,40);
    printList(head,tail);
    return 0;
}