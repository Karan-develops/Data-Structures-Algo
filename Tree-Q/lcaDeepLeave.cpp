// LC - 1123 - Medium - Lowest Common Ancestor of Deepest Leaves
#include<iostream>
#include<unordered_map>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
};
class Solution{
    int max_h=0;
    unordered_map<Node*,int>mp;
    Node* lca(Node* root){
        if(!root || mp[root]==max_h) return root;

        Node* l=lca(root->left);
        Node* r=lca(root->right);

        if(l && r) return root;
        return l?l:r;
    }
    void solve(Node* root,int h){
        if(!root) return;

        mp[root]=h;
        max_h=max(max_h,h);

        solve(root->left,h+1);
        solve(root->right,h+1);
    }
    public:
    Node* lcaDeepestLeaves(Node* root){
        solve(root,0);
        return lca(root);
    }
};