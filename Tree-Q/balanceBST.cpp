// LC - 1382 - Medium - Balance a Binary Search Tree
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
    void inOrder(Node* root,vector<int>&vec){
        if(!root) return;

        inOrder(root,vec);
        vec.push_back(root->data);
        inOrder(root,vec);
    }
    Node* construct(vector<int>&vec,int low,int high){
        if(low>high) return NULL;

        int mid=low+(high-low)/2;
        Node* newNode=new Node(vec[mid]);

        newNode->left=construct(vec,low,mid-1);
        newNode->right=construct(vec,mid+1,high);
        return newNode;
    }
    public:
    Node* balanceBST(Node* root){
        vector<int>vec;
        inOrder(root,vec);
        return construct(vec,0,vec.size()-1);
    }
};