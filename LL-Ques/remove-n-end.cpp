// LC - 19 - Medium - Remove Nth Node From End of List
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};
Node* removeNthFromEnd(Node* head, int n){
    Node* slow=head;
    Node* fast=head;

    for(int i=0;i<n;i++){
        fast=fast->next;
    }
    if(!fast) return head->next;

    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    Node* temp=slow->next;
    slow->next=slow->next->next;
    delete(temp);
    return head;
}