// LC - 328 - Medium - Odd Even Linked List
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};
class Solution{
    public:
    Node* oddEvenList(Node* head){
        if(!head || !head->next) return head;
        Node* odd=head;
        Node* even=head->next;
        Node* evenHead=even;

        while(even && even->next){
            odd->next=even->next;
            odd=odd->next;
            even->next=even->next->next;
            even=even->next;
        }
        odd->next=evenHead;
        return head;
    }
};
/*
Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]

Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
*/