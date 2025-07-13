// LC - 86 - Medium - Partition List
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
    ListNode* partition(ListNode* head,int x){
        ListNode* small=new ListNode(0);
        ListNode* large=new ListNode(0);

        ListNode* smallP=small;
        ListNode* largeP=large;

        while(head){
            if(head->val<x){
                smallP->next=head;
                smallP=smallP->next;
            } else{
                largeP->next=head;
                largeP=largeP->next;
            }
            head=head->next;
        }

        largeP->next=NULL;
        smallP->next=large->next;
        return small->next;
    }
};
/*
-> Example 1:
Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
:-----------------------:
-> Example 2:
Input: head = [2,1], x = 2
Output: [1,2]
*/