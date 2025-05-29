// LC - 108 - Easy - Convert Sorted Array to Binary Search Tree
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
class BST{
    Node* solve(vector<int>&nums,int l,int r){
        if(l>r) return NULL;

        int mid=l+(r-l)/2;
        Node* newNode=new Node(nums[mid]);

        newNode->left=solve(nums,l,mid-1);
        newNode->right=solve(nums,mid+1,r);

        return newNode;
    }
    public:
    Node* sortedArrayToBST(vector<int>&nums){
        return solve(nums,0,nums.size()-1);
    }
};
/*
-> Example 1:
Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
:-------------------------:
-> Example 2:
Input: nums = [1,3]
Output: [3,1]
*/