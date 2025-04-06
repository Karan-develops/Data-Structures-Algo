// LC - 938 - Easy - Range Sum of BST
// 2 Approaches
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
};
class Solution1{
    int ans=0;
    void solve(Node* root,int l,int h){
        if(!root) return;

        solve(root->left,l,h);
        if(root->data>=l && root->data<=h) ans+=root->data;
        solve(root->right,l,h);
    }
    public:
    int rangeSumBST(Node* root,int low,int high){
        solve(root,low,high);
        return ans;
    }
};
class Solution2{
    int ans=0;
    int solve(Node* root,int l,int h){
        if(!root) return;

        if(root->data>=l && root->data<=h){
            return root->data+solve(root->left,l,h)+solve(root->right,l,h);
        }

        //When outside the range (Less than low) - Go right
        if(root->data<l){
            return solve(root->right,l,h);
        }
        //When outside the range (Greater than high) - Go left
        return solve(root->left,l,h);
    }
    public:
    int rangeSumBST(Node* root,int low,int high){
        return solve(root,low,high);
    }
};