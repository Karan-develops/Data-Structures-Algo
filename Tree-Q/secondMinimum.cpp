// LC - 671 - Easy - Second Minimum Node In a Binary Tree
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
    int rootdata;
    long ans=LONG_MAX;
    void solve(Node* root){
        if(!root) return;

        if(root->data>rootdata && root->data<ans){
            ans=root->data;
        } else if(rootdata==root->data){
            solve(root->left);
            solve(root->right);
        }
    }
    int findSecondMinimumdataue(Node* root){
        rootdata=root->data;
        solve(root);
        return ans==LONG_MAX?-1:(int)ans;
    }
};
/*
Example 1:
Input: root = [2,2,5,null,null,5,7]
Output: 5

Example 2:
Input: root = [2,2,2]
Output: -1
*/