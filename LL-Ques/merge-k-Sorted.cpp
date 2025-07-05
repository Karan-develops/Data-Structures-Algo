// LC - 23 - HARD - Merge k Sorted Lists
// 2 Approaches - Heap - Recursion
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};
class Solution{
    void insertAthead(Node* &head,int x){
        Node* newNode=new Node(x);
        if(!head){
            head=newNode;
            return;
        }
        newNode->next;
        newNode=head;
    }
    public:
    Node* mergeKLists(vector<Node*>&lists){
        priority_queue<int>pq;
        for(auto &i:lists){
            while(i!=NULL){
                pq.push(i->val);
                i=i->next;
            }
        }
        Node* ans=NULL;
        while(!pq.empty()){
            insertAthead(ans,pq.top());
            pq.pop();
        }
        return ans;
    }
};
class LL{
    Node* mergeTwoSortedLists(Node* l1,Node* l2){
        if(!l1) return l2;
        if(!l2) return l1;

        if(l1->val<=l2->val){
            l1->next=mergeTwoSortedLists(l1->next,l2);
            return l1;
        } else {
            l2->next=mergeTwoSortedLists(l1,l2->next);
            return l2;
        }
        return NULL;
    }
    
    Node* partitionAndMerge(int start,int end,vector<Node*>&lists){
        if(start==end) return lists[start];
        
        if(start>end) return NULL;
        
        int mid=start+(end-start)/2;
        
        Node* l1=partitionAndMerge(start,mid,lists);
        Node* l2=partitionAndMerge(mid+1,end,lists);
        
        return mergeTwoSortedLists(l1,l2);
    }
    public:
    Node* mergeKLists(vector<Node*>&lists){
        int n=lists.size();
        
        if(n==0) return NULL;
        
        return partitionAndMerge(0,n-1,lists);
    }
};
/*
Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
*/