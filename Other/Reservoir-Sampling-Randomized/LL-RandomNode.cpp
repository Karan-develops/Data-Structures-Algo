// LC - 382 - Medium - Linked List Random Node
#include<iostream>
#include<math.h>
using namespace std;
class ListNode{
    public:
    int data;
    ListNode* next;
};
class Solution{
    int n;
    ListNode* ll;
    public:
    Solution(ListNode* head){
        int count=0;
        ll=head;
        ListNode* temp=head;
        while(temp){
            temp=temp->next;
            count++;
        }
        this->n=count;
    }
    
    int getRandom(){
        int randNum=rand()%n;
        ListNode* temp=ll;
        while(randNum--){
            temp=temp->next;
        }
        return temp->data;
    }
};
/*
- Input:
["Solution", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom"]
[[[1, 2, 3]], [], [], [], [], []]
- Output:
[null, 1, 3, 2, 2, 3]
*/