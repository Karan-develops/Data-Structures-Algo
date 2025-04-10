// LC - 236 - Medium - Lowest Common Ancestor of a Binary Tree
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
};
class Solution{
    public:
    Node* lowestCommonAncestor(Node* root, Node* p, Node* q){
        if(!root || root->data==p->data || root->data==q->data) return root;

        Node *l=lowestCommonAncestor(root->left,p,q);
        Node *r=lowestCommonAncestor(root->right,p,q);

        if(l && r) return root;
        
        return l?l:r;
    }
};