// LC - 138 - Medium - Copy List with Random Pointer
// 2 Approaches
#include<iostream>
#include<unordered_map>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node* random;
    Node(int val){
        this->val=val;
        this->next=NULL;
        this->random=NULL;
    }
};
class LL_Map{
    public:
    Node* copyRandomList(Node* head){
        if(!head) return NULL;
        
        Node* temp=head;
        Node* newHead=NULL;
        Node* prev=newHead;

        unordered_map<Node*,Node*>mp;

        while(temp){
            Node* newNode=new Node(temp->val);
            mp[temp]=newNode;

            if(!newHead){
                newHead=newNode;
                prev=newHead;
            } else{
                prev->next=newNode;
                prev=newNode;
            }
            temp=temp->next;
        }

        // Fill Random Pointers
        temp=head;
        Node* newTemp=newHead;

        while(temp){
            newTemp->random=mp[temp->random];
            newTemp=newTemp->next;
            temp=temp->next;
        }

        return newHead;
    }
};
// Approach 2
class LL{
    public:
    Node* copyRandomList(Node* head){
        if(!head) return NULL;

        // Step 1 : Make List like A -> X -> B -> Y ----
        // (A,B are Original Nodes) &  (X,Y are Copied)
        Node* curr=head;
        while(curr){
            Node* temp=curr->next;
            curr->next=new Node(curr->val);
            curr->next->next=temp;
            curr=temp;
        }

        // Step 2 : Deep Copy Random Ptrs
        curr=head;
        while(curr && curr->next){
            curr->next->random=curr->random?curr->random->next:NULL;
            curr=curr->next->next;
        }

        // Step 3 : Seperate Both LL Back
        curr=head;
        Node* newHead=head->next;
        Node* newCurr=newHead;

        while(curr && newCurr){
            curr->next=curr->next?curr->next->next:NULL;
            newCurr->next=newCurr->next?newCurr->next->next:NULL;

            curr=curr->next;
            newCurr=newCurr->next;
        }
        return newHead;
    }
};