// Don't reverse lists on LEETCODE.
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
        return;
    }
    tail->next=newNode;
    tail=newNode;
}
Node* revList(Node* head){
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
Node* addTwoNumbersInLL(Node* &list1,Node* &list2){
    Node* head1=revList(list1);
    Node* head2=revList(list2);
    Node* ansNode=NULL;
    Node* ansTail=NULL;
    Node* temp1=head1;
    Node* temp2=head2;
    int carry=0;
    while(temp1!=NULL && temp2!=NULL){
        int digit=temp1->data+temp2->data+carry;
        carry=digit/10;
        digit%=10;
        Node* digitNode=new Node(digit);
        if(ansNode==NULL){
            ansNode=digitNode;
            ansTail=digitNode;
        } else{
            ansTail->next=digitNode;
            ansTail=digitNode;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    while(temp1!=NULL){
        int digit=temp1->data+carry;
        carry=digit/10;
        digit%=10;
        Node* digitNode=new Node(digit);
        ansTail->next=digitNode;
        ansTail=digitNode;
        temp1=temp1->next;
    }
    while(temp2!=NULL){
        int digit=temp2->data+carry;
        carry=digit/10;
        digit%=10;
        Node* digitNode=new Node(digit);
        ansTail->next=digitNode;
        ansTail=digitNode;
        temp2=temp2->next;
    }
    if(carry){
        Node* carryNode=new Node(carry);
        ansTail->next=carryNode;
        ansTail=carryNode;
        carry=0;
    }
    ansNode=revList(ansNode);
    return ansNode;
}
int main(){
    Node* head1=NULL;
    Node* tail1=NULL;
    Node* head2=NULL;
    Node* tail2=NULL;
    addNewNodeAtTail(head1,tail1,2);
    addNewNodeAtTail(head1,tail1,4);
    addNewNodeAtTail(head1,tail1,3);
    addNewNodeAtTail(head1,tail1,3);
    // addNewNodeAtTail(head1,tail1,9);
    printList(head1);
    addNewNodeAtTail(head2,tail2,0);
    addNewNodeAtTail(head2,tail2,2);
    addNewNodeAtTail(head2,tail2,3);
    addNewNodeAtTail(head2,tail2,4);
    // addNewNodeAtTail(head2,tail2,9);
    printList(head2);
    Node* ans=addTwoNumbersInLL(head1,head2);
    printList(ans);
    return 0;
}