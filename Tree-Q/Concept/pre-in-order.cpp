// LC - 105 - Medium - Construct Binary Tree from Preorder and Inorder Traversal
#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
class Solution{
    Node* solve(vector<int>&preorder,vector<int>&inorder,int s,int e,int idx){
        if(s>e) return NULL;

        int i=s;
        int val=preorder[idx];
        for(;i<e;i++){
            if(inorder[i]==val) break;
        }
        idx++;
        Node* root=new Node(val);
        root->left=solve(preorder,inorder,s,i-1,idx);
        root->right=solve(preorder,inorder,i+1,e,idx);
        return root;
    }
    public:
    Node* buildTree(vector<int>&preorder,vector<int>&inorder){
        int n=preorder.size();
        int idx=0;
        return solve(preorder,inorder,0,n-1,idx);
    }
};