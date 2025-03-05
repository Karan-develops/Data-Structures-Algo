// LL is sorted
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
    ~Node(){
        cout<<"Node with value: "<<this->data<<" deleted."<<endl;
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
void removeDuplicates(Node* &head){
    if(head==NULL){
        cout<<"LL is empty."<<endl;
        return;
    }
    Node* temp=head;
    while(temp!=NULL && temp->next!=NULL){
        if(temp->data==temp->next->data){
            Node* duplicateNode=temp->next;
            temp->next=duplicateNode->next;
            delete duplicateNode;
        } else{
            temp=temp->next;
        }
    }
}
int main(){
    Node* head=NULL;
    Node* tail=NULL;
    addNewNodeAtTail(head,tail,1);
    addNewNodeAtTail(head,tail,2);
    addNewNodeAtTail(head,tail,2);
    addNewNodeAtTail(head,tail,2);
    addNewNodeAtTail(head,tail,3);
    addNewNodeAtTail(head,tail,4);
    addNewNodeAtTail(head,tail,5);
    addNewNodeAtTail(head,tail,5);
    printList(head);
    removeDuplicates(head);
    printList(head);
    return 0;
}