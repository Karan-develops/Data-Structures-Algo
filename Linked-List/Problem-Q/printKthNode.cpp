// 2 Methods
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
void addNewNodeAtTail(Node *&head,Node* &tail,int data){
    Node* newNode=new Node(data);
    if(head==NULL){
        head=newNode;
        tail=newNode;
        return;
    }
    tail->next=newNode;
    tail=newNode;
}
void printKthNodeUsingLen(Node* &head,Node* &tail,int posFromTail){
    if(posFromTail==0){
        cout<<tail->data<<endl;
        return;
    }
    Node* temp=head;
    int lenOfList=getLength(head);
    int i=1;
    while((lenOfList-posFromTail)>i){
        temp=temp->next;
        i++;
    }
    cout<<temp->data<<endl;
}
void printKthNodeByRecursion(Node* &head,int &posFromTail){
    if(head==NULL) return;
    printKthNodeByRecursion(head->next,posFromTail);
    if(posFromTail==0){
        cout<<head->data<<endl;
    }
    posFromTail--;
}
int main(){
    int posFromTail=4;
    Node* head=NULL;
    Node* tail=NULL;
    addNewNodeAtTail(head,tail,1);
    addNewNodeAtTail(head,tail,2);
    addNewNodeAtTail(head,tail,3);
    addNewNodeAtTail(head,tail,4);
    addNewNodeAtTail(head,tail,5);
    printList(head);
    printKthNodeUsingLen(head,tail,posFromTail);
    printKthNodeByRecursion(head,posFromTail);
    return 0;
}