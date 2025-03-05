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
void printList(Node* &head,Node* &tail){
    if(head->next==NULL){
        cout<<head->data<<endl;
        return;
    }
    cout<<head->data<<" ";
    Node* temp=head->next;
    int i=0;
    while(temp!=head){
        cout<<temp->data<<" ";
        temp=temp->next;
        i++;
    }
    cout<<endl;
}
int getLength(Node* &head,Node* &tail){
    if(head->next==NULL) return 1;
    int len=1;
    Node* temp=head->next;
    while(temp!=head){
        temp=temp->next;
        len++;
    }
    return len;
}
int findValIdx(Node* &head,Node* &tail,int data){
    Node* temp=head;
    int i=1;
    int lenOfList=getLength(head,tail);
    do{
        if(temp->data==data){
            return i;
        }
        temp=temp->next;
        i++;
    } while(temp!=head);
    if(i>lenOfList) return -1;
    return i;
}
void addNodeInLeft(Node* &head,Node* &tail,int data){
    Node* newNode=new Node(data);
    if(head==NULL){
        head=newNode;
        tail=newNode;
        head->next=tail;
        return;
    }
    newNode->next=head;
    head=newNode;
    tail->next=head;
}
void addNodeInRight(Node* &head,Node* &tail,int data){
    Node* newNode=new Node(data);
    if(head==NULL){
        head=newNode;
        tail=newNode;
        head->next=tail;
        return;
    }
    newNode->next=head;
    tail->next=newNode;
    tail=newNode;
}
void addNodeAtPos(Node* &head,Node* &tail,int data,int pos){
    Node* newNode=new Node(data);
    if(pos==0 || pos<0){
        addNodeInLeft(head,tail,data);
        return;
    }
    int lenOfList=getLength(head,tail);
    if(pos>lenOfList){
        addNodeInRight(head,tail,data);
        return;
    }
    Node* temp=head;
    int i=1;
    while(i<pos){
        temp=temp->next;
        i++;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}
void deleteNodeByVal(Node* &head,Node* &tail,int dataVal){
    if(head==NULL){
        cout<<"LL is empty."<<endl;
        return;
    }
    int posOfValue=findValIdx(head,tail,dataVal);
    if(!posOfValue){
        cout<<"Invalid Index!"<<endl;
        return;
    }
    if(head->next==NULL){
        head=NULL;
        tail=NULL;
        return;
    }
    Node* &prevNode=head;
    int i=1;
    while(i<posOfValue-1){
        prevNode=prevNode->next;
        i++;
    }
    Node* currNode=prevNode->next;
    prevNode->next=currNode->next;
    currNode->next=NULL;
    delete currNode;
}
int main(){
    Node* head=NULL;
    Node* tail=NULL;
    addNodeInRight(head,tail,10);
    addNodeInRight(head,tail,20);
    addNodeInRight(head,tail,30);
    addNodeInLeft(head,tail,40);
    addNodeInLeft(head,tail,50);
    addNodeInLeft(head,tail,60);
    printList(head,tail);
    deleteNodeByVal(head,tail,30);
    addNodeAtPos(head,tail,100,5);
    printList(head,tail);
    return 0;
}