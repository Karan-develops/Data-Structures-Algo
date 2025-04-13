// LC - 2095 - Medium - Delete the Middle Node of a Linked List
// 2 Approaches
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};
// Using Prev Pointer
class Solution1{
    public:
    Node* deleteMiddle(Node* head){
        if(!head || !head->next) return NULL;

        Node* slow=head;
        Node* fast=head;
        Node* prev=NULL;

        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }

        prev->next=slow->next;
        delete(slow);
        return head;
    }
};
// Without prev pointer
class Solution2{
    public:
    Node* deleteMiddle(Node* head){
        if(!head || !head->next) return NULL;

        Node* slow=head;
        Node* fast=head->next->next;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        Node* temp=slow->next;
        slow->next=slow->next->next;
        delete(temp);
        return head;
    }
};
// [1,3,4,7,1,2,6]
//      s       f