// LC - 1669 - Medium - Merge In Between Linked Lists
#include<iostream>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode* next;
};
class LL{
    public:
    ListNode* mergeInBetween(ListNode* list1,int a,int b,ListNode* list2){
        ListNode* left=NULL;
        ListNode* right=list1;

        for(int i=0;i<=b;i++){
            if(i==a-1){
                left=right;
            }
            right=right->next;
        }

        left->next=list2;
        while(left->next){
            left=left->next;
        }

        left->next=right;
        return list1;
    }
};
/*
-> Example 1:
Input: list1 = [10,1,13,6,9,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
Output: [10,1,13,1000000,1000001,1000002,5]
:--------------------------:
-> Example 2:
Input: list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 = [1000000,1000001,1000002,1000003,1000004]
Output: [0,1,1000000,1000001,1000002,1000003,1000004,6]
*/