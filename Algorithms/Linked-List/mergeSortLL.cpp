// Merge Sort Linked List
#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
};
class LL{
    Node* mergeTwoLists(Node* l1,Node* l2){
        if(!l1) return l2;
        if(!l2) return l1;

        if(l1->val<=l2->val){
            l1->next=mergeTwoLists(l1->next,l2);
            return l1;
        }

        l2->next=mergeTwoLists(l1,l2->next);
        return l2;
    }
    Node* mergeAndSort(Node* head){
        if(!head || !head->next) return head;

        Node* prev=NULL;
        Node* slow=head;
        Node* fast=head;

        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }

        prev->next=NULL;

        Node* left=mergeAndSort(head);
        Node* right=mergeAndSort(slow);

        return mergeTwoLists(left,right);
    }
    public:
    Node* mergeSort(Node* head){
        return mergeAndSort(head);
    }
};