// LC - 725 - Medium - Split Linked List in Parts
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
    vector<ListNode*> splitListToParts(ListNode* head,int k){
        ListNode* temp=head;
        int count=0;

        while(temp){
            temp=temp->next;
            count++;
        }

        int extra=count%k;
        int eachBucketSize=count/k;
        vector<ListNode*>ans(k,NULL);

        ListNode* curr=head;
        ListNode* prev=NULL;

        for(int i=0;i<k && curr;i++){
            ans[i]=curr;

            for(int j=0;j<eachBucketSize+(extra>0?1:0);j++){
                prev=curr;
                curr=curr->next;
            }

            prev->next=NULL;
            extra--;
        }
        return ans;
    }
};
/*
-> Example 1:
Input: head = [1,2,3], k = 5
Output: [[1],[2],[3],[],[]]
:-------------------------:
-> Example 2:
Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
Output: [[1,2,3,4],[5,6,7],[8,9,10]]
*/