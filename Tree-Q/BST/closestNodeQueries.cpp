// LC - 2476 - Medium - Closest Nodes Queries in a Binary Search Tree
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
};
class BST{
    void solve(TreeNode* root,vector<int>&temp){
        if(!root) return;

        solve(root->left,temp);
        temp.push_back(root->data);
        solve(root->right,temp);
    }
    public:
    vector<vector<int>> closestNodes(TreeNode* root,vector<int>&queries){
        int n=queries.size();
        vector<vector<int>>ans;
        vector<int>temp;

        solve(root,temp);

        for(int &q:queries){
            auto x=lower_bound(begin(temp),end(temp),q);
            auto y=upper_bound(begin(temp),end(temp),q);

            int minVal=-1,maxVal=-1;

            if(x!=temp.end()) maxVal=*x;

            if(x!=temp.end() && *x==q) minVal=maxVal;
            else if(x!=temp.begin()) minVal=*(prev(x));

            ans.push_back({minVal,maxVal});
        }
        return ans;
    }
};
/*
-> Example 1:
Input: root = [6,2,13,1,4,9,15,null,null,null,null,null,null,14], queries = [2,5,16]
Output: [[2,2],[4,6],[15,-1]]
:--------------------------:
-> Example 2:
Input: root = [4,null,9], queries = [3]
Output: [[-1,4]]
*/