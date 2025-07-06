// LC - 206 - Easy - Reverse Linked List
// Iterative - Recursive
#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
};
class LL{
    Node* solve(Node* curr,Node* prev){
        if(!curr) return prev;

        Node* temp=curr->next;
        curr->next=prev;

        return solve(temp,curr);
    }
    public:
    // Recursive
    Node* reverseListRecursive(Node* head){
        return solve(head,NULL);
    }
    // Iterative
    Node* reverseListIterative(Node* head){
        Node* prev=NULL;

        while(head){
            Node* next=head->next;
            head->next=prev;
            prev=head;
            head=next;
        }
        return prev;
    }
};