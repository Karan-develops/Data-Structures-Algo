// GFG - Sum Tree
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
};
class DFS{
    int solve(Node* root){
        if(!root) return 0;
        
        int l=solve(root->left);
        int r=solve(root->right);
        
        if((l!=0 || r!=0) && root->data!=l+r) return -1;

        if(l==-1 || r==-1) return -1;
        
        return l+r+root->data;
    }
    public:
    bool isSumTree(Node* root){
        int x=solve(root);
        return x==-1?false:true;
    }
};