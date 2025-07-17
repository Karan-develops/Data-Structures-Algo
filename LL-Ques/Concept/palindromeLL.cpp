// LC - 234 - Easy - Palindrome Linked List
// 4 Approaches
#include<iostream>
#include<vector>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode* next;
};
// Approach 1 - Using Extra Vector Space
class LL_vector{
    public:
    bool isPalindrome(ListNode* head){
        ListNode* temp=head;
        vector<int>vec;

        while(temp){
            vec.push_back(temp->val);
            temp=temp->next;
        }

        int i=0,j=vec.size()-1;

        while(i<j){
            if(vec[i++]!=vec[j--]) return false;
        }
        return true;
    }
};
// Approach 2 - Reverse LL from second half
class LL_Rev{
    ListNode* revList(ListNode* curr){
        ListNode* prev=NULL;

        while(curr){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    public:
    bool isPalindrome(ListNode* head){
        if(!head || !head->next) return true;

        ListNode* prev=NULL;
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* revHead=revList(slow);
        prev->next=NULL;

        while(head && revHead){
            if(head->val != revHead->val) return false;

            head=head->next;
            revHead=revHead->next;
        }
        return true;
    }
};
// Approach 3 - Reverse LL from first half
class LL_Rev_2{
    public:
    bool isPalindrome(ListNode* head){
        if(!head || !head->next) return true;

        ListNode* prev=NULL;
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast && fast->next){
            fast=fast->next->next;
            
            ListNode* next=slow->next;
            slow->next=prev;
            prev=slow;
            slow=next;
        }

        // For Odd Length LL
        if(fast) slow=slow->next;

        while(prev && slow){
            if(prev->val != slow->val) return false;

            prev=prev->next;
            slow=slow->next;
        }
        return true;
    }
};
// Approach 4 - Using Pure Recursion
class LL_Recursion{
    ListNode* curr;
    bool solve(ListNode* head){
        if(!head) return true;

        bool ans=solve(head->next);

        if(curr->val!=head->val) return false;
        curr=curr->next;

        return ans;
    }
    public:
    bool isPalindrome(ListNode* head){
        curr=head;

        return solve(head);
    }
};