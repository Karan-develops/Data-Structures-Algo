// LC - 445 - Medium - Add Two Numbers II
// 2 Approaches
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
// Approach 1 - Reverse LL
class LL{
    ListNode* reverse(ListNode* l1){
        ListNode* prev=NULL;

        while(l1){
            ListNode* next=l1->next;
            l1->next=prev;
            prev=l1;
            l1=next;
        }
        return prev;
    }
    public:
    ListNode* addTwoNumbers(ListNode* l1,ListNode* l2){
        ListNode* list1=reverse(l1);
        ListNode* list2=reverse(l2);
        
        ListNode* ans=NULL;
        int carry=0;
        
        while(list1 || list2 || carry){
            int sum=(list1?list1->val:0)+(list2?list2->val:0)+carry;
            carry=sum/10;

            ListNode* newNode=new ListNode(sum%10);
            newNode->next=ans;
            ans=newNode;

            if(list1) list1=list1->next;
            if(list2) list2=list2->next;
        }
        return ans;
    }
};
// Approach 2 - Without reversing LL
class LL2{
    public:
    ListNode* addTwoNumbers(ListNode* l1,ListNode* l2){
        stack<int>s1,s2;

        while(l1){
            s1.push(l1->val);
            l1=l1->next;
        }
        while(l2){
            s2.push(l2->val);
            l2=l2->next;
        }

        ListNode* ans=NULL;
        int sum=0,carry=0;

        while(!s1.empty() || !s2.empty() || carry){
            sum=carry;
            if(!s1.empty()){
                sum+=s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                sum+=s2.top();
                s2.pop();
            }
            
            carry=sum/10;
            
            ListNode* newNode=new ListNode(sum%10);
            newNode->next=ans;
            ans=newNode;
        }
        return ans;
    }
};
/*
-> Example 1:
Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]
:-------------------:
-> Example 2:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]
:-------------------:
-> Example 3:
Input: l1 = [0], l2 = [0]
Output: [0]
*/