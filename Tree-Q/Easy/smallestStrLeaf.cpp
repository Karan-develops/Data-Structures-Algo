// LC - 988 - Medium - Smallest String Starting From Leaf
#include<iostream>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
};
class DFS{
    string ans;
    void solve(TreeNode* root,string temp){
        if(!root) return;

        temp=((char)(root->val+'a'))+temp;

        if(!root->left && !root->right){
            if(ans.empty() || ans>temp){
                ans=temp;
            }
            return;
        }

        solve(root->left,temp);
        solve(root->right,temp);
    }
    public:
    string smallestFromLeaf(TreeNode* root){
        ans="";
        solve(root,"");

        return ans;
    }
};
/*
-> Example 1:
Input: root = [0,1,2,3,4,3,4]
Output: "dba"
:---------------------------:
-> Example 2:
Input: root = [25,1,3,1,3,0,2]
Output: "adz"
:---------------------------:
-> Example 3:
Input: root = [2,2,1,null,1,0,null,0]
Output: "abc"
*/