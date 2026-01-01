// GFG - Medium - Intersection in Y Shaped Lists
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};
class Solution {
  public:
    Node* intersectPoint(Node* head1,Node* head2){
        Node* p1=head1;
        Node* p2=head2;
        
        while(p1!=p2){
            p1=(p1==NULL)?head2:p1->next;
            p2=(p2==NULL)?head1:p2->next;
        }
        
        return p1;
    }
};
/*
Input: head1: 10 -> 15 -> 30, head2: 3 -> 6 -> 9 -> 15 -> 30
Output: 15
:----------------------:
Input: head1: 4 -> 1 -> 8 -> 5, head2: 5 -> 6 -> 1 -> 8 -> 5
Output: 1
*/