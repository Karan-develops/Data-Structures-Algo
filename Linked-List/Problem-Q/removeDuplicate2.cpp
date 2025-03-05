// Unsorted LL
#include<iostream>
#include<unordered_map>
using namespace std;
unordered_map<int,bool>storeDups;
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
        cout<<"Node with value: "<<this->data<<" deleted"<<endl;
    }
};
void printList(Node* &head){
    Node* currNode=head;
    while(currNode!=NULL){
        cout<<currNode->data<<" ";
        currNode=currNode->next;
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
void removeDuplicate2(Node* &head){
    if(head==NULL){
        cout<<"LL is empty."<<endl;
        return;
    }
    Node* prevNode=head;
    Node* currNode=head->next;
    storeDups[prevNode->data]=true;
    while(prevNode!=NULL && currNode!=NULL){
        if(storeDups[currNode->data]==true){
            Node* duplicateNode=currNode;
            prevNode->next=duplicateNode->next;
            currNode=duplicateNode->next;
            duplicateNode->next=NULL;
            delete duplicateNode;
        } else{
            storeDups[currNode->data]=true;
            prevNode=prevNode->next;
            currNode=currNode->next;
        }
    }
}
int main(){
    Node* head=NULL;
    Node* tail=NULL;
    addNewNodeAtTail(head,tail,4);
    addNewNodeAtTail(head,tail,2);
    addNewNodeAtTail(head,tail,1);
    addNewNodeAtTail(head,tail,4);
    addNewNodeAtTail(head,tail,2);
    addNewNodeAtTail(head,tail,7);
    printList(head);
    removeDuplicate2(head);
    printList(head);
    return 0;    
}