// LC - 237 - Medium - Delete Node in a Linked List
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};
// Head pointer not given -- Just the node which has to be deleted
class Solution{
    public:
    void deleteNode(Node* node){
        node->data=node->next->data;
        node->next=node->next->next;
    }
};