// LC - 1290 - Easy - Convert Binary Number in a Linked List to Integer
// 2 Approaches - Reverse LL - Bit Manipulation
#include<iostream>
#include<math.h>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode* next;
};
// Approach 1 - Reversing LL
class LL{
    ListNode* reverseLL(ListNode* head){
        ListNode* prev=NULL;

        while(head){
            ListNode* next=head->next;
            head->next=prev;
            prev=head;
            head=next;
        }
        return prev;
    }
    public:
    int getDecimalValue(ListNode* head){
        head=reverseLL(head);

        int ans=0,power=0;
        while(head){
            if(head->val==1){
                ans+=(pow(2,power));
            }
            power++;
            head=head->next;
        }
        return ans;
    }
};
// Approach 2 - Using Bit Manipulation
class Bit{
    public:
    int getDecimalValue(ListNode* head){
        int ans=0;

        while(head){
            ans=(ans<<1) | (head->val);

            head=head->next;
        }        
        return ans;
    }
};
/*
-> Example 1:
Input: head = [1,0,1]
Output: 5
:----------------------------:
-> Example 2:
Input: head = [0]
Output: 0
*/