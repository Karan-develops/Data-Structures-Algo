// LC - 142 - Medium - Linked List Cycle II
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
class Solution {
    public:
    Node *detectCycle(Node *head) {
        Node* slow=head;
        Node* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) break;
        }
        if(!fast || !fast->next) return NULL;
        Node* temp2=head;
        while(temp2!=slow){
            temp2=temp2->next;
            slow=slow->next;
        }
        return slow;
    }
};