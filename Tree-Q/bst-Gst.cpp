// LC - 1038 - Medium - Binary Search Tree to Greater Sum Tree
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
};
class Solution{
    void solve(Node* root,int &sum){
        if(!root) return;

        solve(root->right,sum);
        sum+=root->data;
        root->data=sum;
        solve(root->left,sum);
    }
    public:
    Node* bstToGst(Node* root){
        int sum=0;
        solve(root,sum);
        return root;
    }
};