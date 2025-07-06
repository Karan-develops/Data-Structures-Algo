// LC - 1721 - Medium - Swapping Nodes in a Linked List
// 2 Approaches - 2 Pass - 1 Pass
#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
};
class LL{
    public:
    // 1 Pass
    Node* swapNodes(Node* head,int k){
        Node* P1=NULL;
        Node* P2=NULL;

        Node* temp=head;

        while(temp){
            if(P2!=NULL){
                P2=P2->next;
            }

            k--;

            if(k==0){
                P1=temp;
                P2=head;
            }
            temp=temp->next;
        }

        swap(P1->val,P2->val);

        return head;
    }
    // 2 Pass
    Node* swapNodes2(Node* head,int k){
        Node* temp=head;
        int count=0;

        int first=-1;
        Node* start=NULL;

        while(temp){
            count++;
            if(count==k){
                first=temp->val;
                start=temp;
            }
            temp=temp->next;
        }

        temp=head;
        for(int i=1;i<=count-k;i++){
            temp=temp->next;
        }
        start->val=temp->val;
        temp->val=first;
        return head;
    }
};