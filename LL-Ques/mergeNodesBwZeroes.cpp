// LC - 2181 - Medium - Merge Nodes in Between Zeros
// 2 Approaches
#include<iostream>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode* next;
};
// Approach 1 - Using 2 Pointers
class LL{
    public:
    ListNode* mergeNodes(ListNode* head){
        ListNode* P1=head->next;
        ListNode* P2=P1;

        while(P2){
            int sum=0;

            while(P2 && P2->val!=0){
                sum+=P2->val;
                P2=P2->next;
            }

            P1->val=sum;
            P2=P2->next;
            P1->next=P2;
            P1=P1->next;
        }
        return head->next;
    }
};
// Approach 2 - Using Recursion
class LL_Rec{
    public:
    ListNode* mergeNodes(ListNode* head){
        head=head->next;
        if(!head) return head;

        ListNode* temp=head;
        int sum=0;

        while(temp && temp->val!=0){
            sum+=temp->val;
            temp=temp->next;
        }

        head->val=sum;
        head->next=mergeNodes(temp);
        return head;
    }
};