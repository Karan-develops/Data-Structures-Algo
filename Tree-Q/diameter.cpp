// LC - 543 - Easy - Diameter of Binary Tree
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
};
class Solution{
    pair<int,int> solve(Node* root){
        if(!root) return {0,0};

        auto [leftHeight,leftDiameter]=solve(root->left);
        auto [rightHeight,rightDiameter]=solve(root->right);

        int height=max(leftHeight,rightHeight)+1;
        int diameter=max(max(leftDiameter,rightDiameter),leftHeight+rightDiameter);

        return {height,diameter};
    }
    public:
    int diameterOfBinaryTree(Node* root){
        return solve(root).second;
    }
};