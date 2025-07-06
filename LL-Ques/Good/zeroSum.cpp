// LC - 1171 - Medium - Remove Zero Sum Consecutive Nodes from Linked List
#include<iostream>
#include<unordered_map>
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
class LL{
    public:
    Node* removeZeroSumSublists(Node* head){
        Node* dummyNode=new Node(0);
        dummyNode->next=head;
        unordered_map<int,Node*>mp;

        mp[0]=dummyNode;
        int prefixSum=0;

        while(head){
            prefixSum+=head->val;
            if(mp.find(prefixSum)!=mp.end()){
                // Deletion
                Node* start=mp[prefixSum];
                Node* temp=start;
                int currSum=prefixSum;

                while(temp!=head){
                    temp=temp->next;
                    currSum+=temp->val;

                    if(temp!=head){
                        mp.erase(currSum);
                    }
                }
                start->next=head->next;
            } else{
                mp[prefixSum]=head;
            }
            head=head->next;
        }
        return dummyNode->next;
    }
};
/*
-> Example 1:
Input: head = [1,2,-3,3,1]
Output: [3,1]
:-------------------------:
-> Example 2:
Input: head = [1,2,3,-3,4]
Output: [1,2,4]
:-------------------------:
-> Example 3:
Input: head = [1,2,3,-3,-2]
Output: [1]
*/