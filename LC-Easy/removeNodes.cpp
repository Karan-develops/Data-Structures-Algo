// LC - 203 - Easy - Remove Linked List Elements
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};
Node* removeElements(Node* head, int val) {
    while(head && head->data==val){
        head=head->next;
    }

    Node* curr=head;

    while(curr && curr->next){
        if(curr->next->data==val){
            curr->next=curr->next->next;
        } else{
            curr=curr->next;
        }
    }
    return head;
}