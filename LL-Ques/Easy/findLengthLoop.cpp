// GFG - Find length of Loop
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};
class LL{
    public:
    int lengthOfLoop(Node *head){
        Node* slow=head;
        Node* fast=head;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) break;
        }
        
        if(!fast || !fast->next) return 0;
        
        int count=1;
        Node* temp=slow->next;
        
        while(temp!=slow){
            count++;
            temp=temp->next;
        }
        return count;
    }
};