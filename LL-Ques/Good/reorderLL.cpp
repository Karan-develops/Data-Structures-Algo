// LC - 143 - Medium - Reorder List
// 3 Approaches
#include<iostream>
#include<stack>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode* next;
};
// Approach 1 - Using Stack
class LL_Stack{
    public:
    void reorderList(ListNode* head){
        ListNode* curr=head;
        stack<ListNode*>st;

        while(curr){
            st.push(curr);
            curr=curr->next;
        }

        int n=st.size()/2;
        curr=head;

        while(n--){
            ListNode* topNode=st.top();
            st.pop();

            ListNode* temp=curr->next;
            curr->next=topNode;
            topNode->next=temp;
            curr=temp;
        }
        curr->next=NULL;
    }
};
// Approach 2 - Reversing 2nd Half of LL
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
    void reorderList(ListNode* head){
        if(!head || !head->next || !head->next->next) return;

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* revHalf=revList(slow);
        ListNode* curr=head;
        
        while(revHalf->next){
            ListNode* currNext=curr->next;
            curr->next=revHalf;

            ListNode* revHalfNext=revHalf->next;
            revHalf->next=currNext;

            revHalf=revHalfNext;
            curr=currNext;
        }
    }
};
// Approach 3 - Using Pure Recursion
class LL_Recursion{
    ListNode* curr;
    void solve(ListNode* head){
        if(!head) return;

        solve(head->next);

        ListNode* temp=curr->next;
        
        if(temp==NULL) return;
        else if(head==curr){
            head->next=NULL;
            return;
        }

        curr->next=head;
        head->next=temp==head?NULL:temp;

        curr=temp;
    }
    public:
    void reorderList(ListNode* head){
        curr=head;
        
        solve(head);
    }
};