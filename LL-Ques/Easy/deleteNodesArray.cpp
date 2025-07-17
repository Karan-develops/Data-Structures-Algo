// LC - 3217 - Medium - Delete Nodes From Linked List Present in Array
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode* next;
};
class LL{
    public:
    ListNode* modifiedList(vector<int>&nums,ListNode* head){
        unordered_set<int>st(begin(nums),end(nums));

        ListNode* curr=head;
        ListNode* prev=NULL;

        while(curr && st.count(curr->val)){
            head=curr->next;
            curr=head;
        }

        while(curr){
            if(st.count(curr->val)){
                prev->next=curr->next;
            } else{
                prev=curr;
            }
            curr=curr->next;
        }
        return head;
    }
};