// LC - 2487 - Medium - Remove Nodes From Linked List
// 3 Approaches
#include<iostream>
#include<stack>
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
// Approach 1 - Using Stack
class LL_Stack{
    public:
    ListNode* removeNodes(ListNode* head){
        ListNode* curr=head;
        stack<ListNode*>st;

        while(curr){
            st.push(curr);
            curr=curr->next;
        }

        curr=st.top();
        st.pop();
        int maxVal=curr->val;
        ListNode* ans=new ListNode(maxVal);

        while(!st.empty()){
            curr=st.top();
            st.pop();

            if(curr->val<maxVal) continue;
            else{
                ListNode* newNode=new ListNode(curr->val);
                newNode->next=ans;
                ans=newNode;
                maxVal=curr->val;
            }
        }
        return ans;
    }
};
// Approach 2 - Using Pure Recursion
class LL_Recursion{
    public:
    ListNode* removeNodes(ListNode* head){
        if(!head || !head->next) return head;

        ListNode* next=removeNodes(head->next);

        if(head->val<next->val){
            return next;
        }

        head->next=next;
        return head;
    }
};
// Approach 3 - Reversing LL
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
    ListNode* removeNodes(ListNode* head){
        if(!head || !head->next) return head;

        head=revList(head);
        
        int maxVal=0;
        ListNode* prev=NULL;
        ListNode* curr=head;

        while(curr){
            maxVal=max(maxVal,curr->val);

            if(curr->val<maxVal){
                if(prev==NULL){
                    // We're deleting the head of the list
                    head=curr->next;
                    curr=head;
                } else{
                    prev->next=curr->next;
                    curr=curr->next;
                }
            }
            else{
                prev=curr;
                curr=curr->next;
            }
        }

        return revList(head);
    }
};