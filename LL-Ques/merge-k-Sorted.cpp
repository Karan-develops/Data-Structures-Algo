// LC - 23 - HARD - Merge k Sorted Lists
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
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
                pq.push(i->data);
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