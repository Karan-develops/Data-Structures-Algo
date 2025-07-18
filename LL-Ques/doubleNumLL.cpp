// LC - 2816 - Medium - Double a Number Represented as a Linked List
// 4 Approaches
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
// Approach 1 - Reversing LL
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
    ListNode* doubleIt(ListNode* head){
        head=revList(head);

        ListNode* prev=NULL;
        ListNode* curr=head;
        int carry=0;

        while(curr){
            int newVal=2*curr->val+carry;
            curr->val=newVal%10;

            carry=newVal/10;

            prev=curr;
            curr=curr->next;
        }

        if(carry){
            ListNode* newNode=new ListNode(carry);
            prev->next=newNode;
        }
        return revList(head);
    }
};
// Approach 2 - Using Pure Recursion
class LL_Recursion{
    int solve(ListNode* head){
        if(!head) return 0;

        int carry=solve(head->next);

        int newVal=2*head->val+carry;
        head->val=newVal%10;

        return newVal/10;
    }
    public:
    ListNode* doubleIt(ListNode* head){
        int lastCarry=solve(head);

        if(lastCarry){
            ListNode* newNode=new ListNode(lastCarry);
            newNode->next=head;
            head=newNode;
        }
        return head;
    }
};
// Approach 3 - Using Prev Pointer
class LL_PrevPtr{
    public:
    ListNode* doubleIt(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;

        while(curr){
            int newVal=2*curr->val;

            if(newVal<10){
                curr->val=newVal;
            } else if(prev!=NULL){
                curr->val=newVal%10;
                prev->val+=1;
            } else{
                ListNode* newNode=new ListNode(1);
                newNode->next=curr;
                curr->val=newVal%10;
                head=newNode;
            }

            prev=curr;
            curr=curr->next;
        }
        return head;
    }
};
// Approach 4 - Using 1 Ptr
class LL{
    public:
    ListNode* doubleIt(ListNode* head){
        if(head->val>=5){
            ListNode* newHead=new ListNode(0);
            newHead->next=head;
            head=newHead;
            // We can also Write above 3 Lines as
            // head=new ListNode(0, head);
        }
        
        ListNode* curr=head;
        
        while(curr){
            curr->val=(curr->val*2)%10;
            
            if(curr->next && curr->next->val>=5){
                curr->val+=1;
            }
            curr=curr->next;   
        }
        return head;
    }
};