// LC - 25 - HARD - Reverse Nodes in k-Group
// GFG - HARD - Linked List Group Reverse
#include<iostream>
using namespace std;
class ListNode{
    public:
    int data;
    ListNode* next;
};
// Left-out nodes at the end, shouldn't be reversed.
class LeetCode{
    public:
    ListNode* reverseKGroup(ListNode* head,int k){
        if(!head) return head;

        ListNode* temp=head;
        for(int i=0;i<k;i++){
            if(!temp) return head;
            temp=temp->next;
        }
        
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nextNode=curr->next;
        
        int i=0;
        while(curr && i<k){
            nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
            i++;
        }
        
        head->next=reverseKGroup(nextNode,k);
        
        return prev;
    }
};
// Left-out nodes at the end, should be considered as a group and must be reversed.
class GFG{
    public:
    ListNode *reverseKGroup(ListNode *head,int k){
        if(!head) return head;
        
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nextNode=curr->next;
        
        int i=0;
        while(curr && i<k){
            nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
            i++;
        }
        
        head->next=reverseKGroup(nextNode,k);
        
        return prev;
    }
};