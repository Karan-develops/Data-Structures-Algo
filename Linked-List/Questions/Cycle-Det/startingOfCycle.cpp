// Step 1 -> Move slow ptr 1 step and fast ptr 2 steps until they meet.
// Step 2 -> Move slow ptr to head.
// Step 3 -> Move both ptrs 1 step at each iteration.
// Where they meet is the starting of cycle.
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
void startingOfCycle(Node* &head){
    if(head==NULL){
        cout<<"LL is empty."<<endl;
        return;
    }
    Node* slow=head;
    Node* fast=head;
    slow=slow->next;
    fast=fast->next->next;
    while(fast!=slow){
        slow=slow->next;
        fast=fast->next->next;
    }
    slow=head;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    cout<<slow->data<<endl;
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
    Node* eight=new Node(90);
    head->next=one;
    one->next=two;
    two->next=three;
    three->next=four;
    four->next=five;
    five->next=six;
    six->next=seven;
    seven->next=eight;
    eight->next=four;
    startingOfCycle(head);
    return 0;
}