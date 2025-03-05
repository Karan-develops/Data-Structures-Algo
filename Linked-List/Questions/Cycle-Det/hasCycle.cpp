// Two Approaches - Map and Floyd Cycle Detection
#include<iostream>
#include<unordered_map>
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
// Approach one - using map
unordered_map<Node*,bool>NodeCheck;
bool hasCycleWithMap(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        if(NodeCheck[temp]==true){
            return true;
        }
        NodeCheck[temp]=true;
        temp=temp->next;
    }
    return false;
}
// Approach two - Floyd Cycle Detection
bool hasCycleWithSlowFast(Node* &head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next;
        if(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        if(slow==fast){
            return true;
        }
    }
    return false;
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
    if(hasCycleWithSlowFast(head)){
        cout<<"LL has cycle"<<endl;
    } else{
        cout<<"LL Don't have Cycle"<<endl;
    }
    return 0;
}