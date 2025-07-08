// LC - 1457 - Medium - Pseudo-Palindromic Paths in a Binary Tree
// 2 Approaches - Using Freq Vector - Bit Magic
#include<iostream>
#include<vector>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
};
class Tree{
    int ans=0;
    bool checkPseudoPalindrome(vector<int>&v){
        bool flag=false;
        for(int &i:v){
            if(i&1 && flag) return false;
            if(i&1) flag=true;
        }
        return true;
    }
    void solve(TreeNode* root,vector<int>temp){
        if(!root) return;

        temp[root->val]++;

        // Reached Leaf node
        if(!root->left && !root->right){
            if(checkPseudoPalindrome(temp)) ans++;
        }

        solve(root->left,temp);
        solve(root->right,temp);
    }
    public:
    int pseudoPalindromicPaths (TreeNode* root){
        ans=0;
        vector<int>temp(10,0);

        solve(root,temp);
        return ans;
    }
};
class BitMagic{
    int ans=0;
    void solve(TreeNode* root,int temp){
        if(root){
            temp=temp^(1<<root->val);
            
            if(!root->left && !root->right){
                if((temp&(temp-1))==0){
                    ans++;
                }
            }

            solve(root->left,temp);
            solve(root->right,temp);
        }
    }
    public:
    int pseudoPalindromicPaths (TreeNode* root){
        solve(root,0);
        return ans;
    }
};
/*
Example 1:
Input: root = [2,3,1,3,1,null,1]
Output: 2 
:-------------------------------:
Example 2:
Input: root = [2,1,1,1,3,null,null,null,null,null,1]
Output: 1 
:-------------------------------:
Example 3:
Input: root = [9]
Output: 1
*/