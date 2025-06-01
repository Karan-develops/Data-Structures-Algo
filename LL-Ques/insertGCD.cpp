// LC - 2807 - Medium - Insert Greatest Common Divisors in Linked List
#include<iostream>
#include<numeric>
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
Node* insertGreatestCommonDivisors(Node* head){
    Node* temp=head;

    while(temp && temp->next){
        int x=gcd(temp->data,temp->next->data);
        Node* newNode=new Node(x);
        newNode->next=temp->next;
        temp->next=newNode;
        temp=temp->next->next;
    }
    return head;
}
/*
-> Example 1:
Input: head = [18,6,10,3]
Output: [18,6,6,2,10,1,3]
:--------------------------:
-> Example 2:
Input: head = [7]
Output: [7]
*/