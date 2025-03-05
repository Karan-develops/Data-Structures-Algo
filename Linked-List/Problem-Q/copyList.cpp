// 2 Approach
// store nodes mapping in map
// without map -> 1-> A -> A' 2-> clone it 3-> deattach the nodes
#include<iostream>
#include<unordered_map>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* random;
    Node(){
        this->data=0;
        this->next=NULL;
        this->random=NULL;
    }
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->random=NULL;
    }
};
void printList(Node* &head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    temp=head;
    while(temp){
        if(temp->random==NULL){
            cout<<temp->data<<" -> NULL"<<endl;
        } else{
            cout<<temp->data<<" -> "<<temp->random->data<<endl;
        }
        temp=temp->next;
    }
    cout<<endl;
}
void addNewNodeAtTail(Node* &head,Node* &tail,int data){
    Node* newNode=new Node(data);
    if(!head){
        head=newNode;
        tail=newNode;
        return;
    }
    tail->next=newNode;
    tail=newNode;
}
Node* copyListUsingMap(Node* &oldhead,unordered_map<Node*,Node*>&mp){
    if(!oldhead) return oldhead;
    Node* clonedHead=new Node(oldhead->data);
    mp[oldhead]=clonedHead;
    clonedHead->next=copyListUsingMap(oldhead->next,mp);
    clonedHead->random=mp[oldhead->random];
    return clonedHead;
}
Node* copyListWithoutMap(Node* &head){
    Node* it=head;
    while(it){
        Node* clonedNode=new Node(it->data);
        clonedNode->next=it->next;
        it->next=clonedNode;
        it=it->next->next;
    }
    it=head;
    while(it){
        Node* clonedList=it->next;
        clonedList->random=it->random?it->random->next:NULL;
        it=it->next->next;
    }
    it=head;
    Node* clonedList=it->next;
    while(it && it->next){
        Node* clonedNode=it->next;
        it->next=it->next->next;
        clonedNode->next=clonedNode->next?clonedNode->next->next:NULL;
        it=it->next;
    }
    return clonedList;
}
int main(){
    Node* head=new Node(7);
    Node* one=new Node(13);
    Node* two=new Node(11);
    Node* three=new Node(10);
    Node* four=new Node(1);
    Node* tail=NULL;
    head->next=one;
    head->random=NULL;
    one->next=two;
    one->random=head;
    two->next=three;
    two->random=four;
    three->next=four;
    three->random=two;
    four->next=tail;
    four->random=one;
    cout<<"Original List:"<<endl;
    printList(head);
    cout<<"Deep copied List:"<<endl;
    unordered_map<Node*,Node*>mp;
    // Node* copiedList=copyListUsingMap(head,mp);
    Node* copiedList=copyListWithoutMap(head);
    printList(copiedList);
    return 0;
}