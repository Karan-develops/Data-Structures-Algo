// GFG - Reverse a Doubly Linked List
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;
};
class Solution{
    public:
    Node *reverse(Node *head){
        if (!head || !head->next) return head;

        Node* curr=head;
        Node* temp=NULL;

        while(curr){
            temp=curr->prev;
            curr->prev=curr->next;
            curr->next=temp;
    
            curr=curr->prev;
        }
    
        if(temp) head=temp->prev;
    
        return head;
    }
};