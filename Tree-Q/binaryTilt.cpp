// LC - 563 - Easy - Binary Tree Tilt
#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* left;
    Node* right;
};
class Solution{
    int ans=0;
    int solve(Node* root){
        if(!root) return 0;

        int l=solve(root->left);
        int r=solve(root->right);

        ans+=abs(l-r);

        return l+r+root->val;
    }
    public:
    int findTilt(Node* root){
        solve(root);
        return ans;
    }
};