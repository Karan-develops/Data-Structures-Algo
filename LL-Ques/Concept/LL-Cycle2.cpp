// LC - 142 - Medium - Linked List Cycle II
#include<iostream>
using namespace std;
class Node{
    public:
    Node* next;
};
class LL{
    public:
    Node *detectCycle(Node *head){
        if(!head || !head->next) return NULL;

        Node* slow=head;
        Node* fast=head;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) break;
        }

        if(slow!=fast) return NULL;
        
        Node* temp=head;
        while(temp!=slow){
            temp=temp->next;
            slow=slow->next;
        }
        return slow;
    }
};
/*
-> Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
:-------------------------:
-> Example 2:
Input: head = [1,2], pos = 0
Output: tail connects to node index 0
:-------------------------:
-> Example 3:
Input: head = [1], pos = -1
Output: no cycle
*/