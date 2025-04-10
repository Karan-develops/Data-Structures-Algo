// LC - 872 - Easy - Leaf-Similar Trees
#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
};
class Solution{
    void solve(Node* root,vector<int>&vec){
        if(!root) return;

        solve(root->left,vec);
        solve(root->right,vec);

        if(!root->left && !root->right) vec.push_back(root->data);
    }
    public:
    bool leafSimilar(Node* root1,Node* root2){
        vector<int>v1,v2;
        solve(root1,v1);
        solve(root2,v2);
        return v1==v2;
    }
};