// Same as startingOfCycle just maintain a pointer one node behind the fast pointer to point cyclic node to NULL.
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
void hasCycle(Node* &head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next;
        if(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        if(slow==fast){
            cout<<"LL has cycle."<<endl;
            return;
        }
    }
    cout<<"LL has no cycle."<<endl;
}
void removeCycle(Node* &head){
    Node* slow=head;
    Node* fast=head;
    Node* prevFast=head->next;
    slow=slow->next;
    fast=fast->next->next;
    prevFast=prevFast->next;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next->next;
        prevFast=prevFast->next->next;
    }
    slow=head;
    while(slow!=fast){ 
        slow=slow->next;
        fast=fast->next;
        prevFast=prevFast->next;
    }
    prevFast->next=NULL;
    cout<<"Cycle removed by pointing node with value: "<<prevFast->data<<" to NULL."<<endl;
}
int main(){
    Node* head=new Node(10);
    Node* one=new Node(20);
    Node* two=new Node(30);
    Node* three=new Node(40);
    Node* four=new Node(50);
    Node* five=new Node(60);
    Node* six=new Node(70);
    Node* seven=new Node(80);
    Node* tail=new Node(90);
    head->next=one;
    one->next=two;
    two->next=three;
    three->next=four;
    four->next=five;
    five->next=six;
    six->next=seven;
    seven->next=tail;
    tail->next=four;
    hasCycle(head);
    removeCycle(head);
    hasCycle(head);
    return 0;
}