#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* bottom;
    Node* next;
    Node(){
        this->data=0;
        this->bottom=NULL;
        this->next=NULL;
    }
    Node(int data){
        this->data=data;
        this->bottom=NULL;
        this->next=NULL;
    }
};
void printList(Node* &head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void flattenPrint(Node* &head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->bottom;
    }
    cout<<endl;
}
void addNewNodeAtTail(Node* &head,Node* &tail,int data){
    Node* newNode=new Node(data);
    tail->bottom=newNode;
    tail=newNode;
}
Node* mergeLL(Node* a,Node* b){
    if(!a) return b;
    if(!b) return a;
    Node* ans=NULL;
    if(a->data<b->data){
        ans=a;
        a->bottom=mergeLL(a->bottom,b);
    } else{
        ans=b;
        b->bottom=mergeLL(a,b->bottom);
    }
    return ans;
}
Node* flattenLL(Node* root){
    if(!root) return root;
    return mergeLL(root,flattenLL(root->next));
}
int main(){
    Node* one=new Node(5);
    Node* b1=new Node(7);
    one->bottom=b1;
    Node* b1t=b1;
    addNewNodeAtTail(b1,b1t,8);
    addNewNodeAtTail(b1,b1t,30);
    Node* two=new Node(10);
    one->next=two;
    Node* b2=new Node(20);
    two->bottom=b2;
    Node* three=new Node(19);
    two->next=three;
    Node* b3=new Node(22);
    Node* b3t=b3;
    three->bottom=b3t;
    addNewNodeAtTail(b3,b3t,50);
    Node* four=new Node(28);
    three->next=four;
    Node* b4=new Node(35);
    four->bottom=b4;
    Node* b4t=b4;
    addNewNodeAtTail(b4,b4t,40);
    addNewNodeAtTail(b4,b4t,45);
    printList(one);
    Node* flattenAns=flattenLL(one);
    flattenPrint(flattenAns);
    return 0;
}