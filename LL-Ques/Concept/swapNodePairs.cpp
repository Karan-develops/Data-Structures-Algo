// LC - 24 - Medium - Swap Nodes in Pairs
#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
};
class LL{
    public:
    Node* swapPairs(Node* head){
        if(!head || !head->next) return head;

        Node* temp=head->next;
        head->next=swapPairs(head->next->next); // Recursion Will do the work
        temp->next=head;

        return temp;
    }
};