// LC - 606 - Medium - Construct String from Binary Tree
// Topics --> String, Tree, Depth-First Search, Binary Tree
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
    string tree2str(Node* root){
        if(!root) return "";

        string ans=to_string(root->data);
        string l=tree2str(root->left);
        string r=tree2str(root->right);

        if(!root->left && !root->right){
            return ans;
        }

        if(!root->left){
            return ans+"()"+"("+r+")";
        }

        if(!root->right){
            return ans+"("+l+")";
        }

        return ans+"("+l+")"+"("+r+")";
    }
};
/*
-> Example 1:
Input: root = [1,2,3,4]
Output: "1(2(4))(3)"
:-------------------:
-> Example 2:
Input: root = [1,2,3,null,4]
Output: "1(2()(4))(3)"
*/