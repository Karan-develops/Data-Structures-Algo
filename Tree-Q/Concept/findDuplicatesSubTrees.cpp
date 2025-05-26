// LC - 652 - Medium - Find Duplicate Subtrees
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
};
class Solution{
    string solve(Node* root,unordered_map<string,int>&subTrees,vector<Node*>&ans){
        if(!root) return "$";

        string l=solve(root->left,subTrees,ans);
        string r=solve(root->right,subTrees,ans);

        string s=l+","+r+","+to_string(root->data);

        if(subTrees[s]==1) ans.push_back(root);

        subTrees[s]++;
        return s;
    }
    public:
    vector<Node*> findDuplicateSubtrees(Node* root){

    }
};
/*
-> Example 1:
Input: root = [1,2,3,4,null,2,4,null,null,4]
Output: [[2,4],[4]]
:-------------------:
-> Example 2:
Input: root = [2,1,1]
Output: [[1]]
:-------------------:
-> Example 3:
Input: root = [2,2,2,3,null,3,null]
Output: [[2,3],[3]]
*/