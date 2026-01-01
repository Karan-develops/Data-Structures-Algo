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