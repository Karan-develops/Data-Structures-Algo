// LC - 92 - Medium - Reverse Linked List II
#include<iostream>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode* next;
    ListNode(int val){
        this->val=val;
        this->next=NULL;
    }
};
class LL{
    public:
    ListNode* reverseBetween(ListNode* head,int left,int right){
        if(!head || !head->next) return head;

        ListNode* dummy=new ListNode(0);
        dummy->next=head;

        ListNode* prev=dummy;
        for(int i=1;i<left;i++){
            prev=prev->next;
        }

        ListNode* curr=prev->next;

        for(int i=0;i<right-left;i++){
            ListNode* temp=prev->next;
            prev->next=curr->next;
            curr->next=curr->next->next;
            prev->next->next=temp;
        }
        return dummy->next;
    }
};
/*
-> Example 1:
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
:---------------------:
-> Example 2:
Input: head = [5], left = 1, right = 1
Output: [5]
*/