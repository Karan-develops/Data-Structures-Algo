// LC - 2058 - Medium - Find the Minimum and Maximum Number of Nodes Between Critical Points
#include<iostream>
#include<vector>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode* next;
};
class LL{
    public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head){
        // First & Last Nodes can't be CP
        ListNode* prev=head;
        ListNode* curr=head->next;

        int i=1;
        int firstCPIdx=0;
        int prevCPIdx=0;
        int minDist=INT_MAX;

        while(curr->next){
            if((curr->val<prev->val && curr->val<curr->next->val) ||
               (curr->val>prev->val && curr->val>curr->next->val)){
                    if(prevCPIdx==0){
                        prevCPIdx=i;
                        firstCPIdx=i;
                    } else{
                        minDist=min(minDist,i-prevCPIdx);
                        prevCPIdx=i;
                    }
            }

            i++;
            prev=curr;
            curr=curr->next;
        }

        if(minDist==INT_MAX) return {-1,-1};

        int maxDist=prevCPIdx-firstCPIdx;
        return {minDist,maxDist};
    }
};
/*
-> Example 1:
Input: head = [3,1]
Output: [-1,-1]
:---------------------------------------:
-> Example 2:
Input: head = [5,3,1,2,5,1,2]
Output: [1,3]
:---------------------------------------:
-> Example 3:
Input: head = [1,3,2,2,3,2,2,2,7]
Output: [3,3]
*/