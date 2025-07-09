// LC - 1609 - Medium - Even Odd Tree
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
};
class BFS{
    bool checkEven(queue<TreeNode*>&q,int N){
        int temp=INT_MAX-1;

        while(N--){
            TreeNode* curr=q.front();
            q.pop();

            // The Node shouldn't be ODD , Shouldn't be Larger than prev Node
            if((curr->val & 1) || !(temp>curr->val)) return false;
            temp=curr->val;

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        return true;
    }
    bool checkOdd(queue<TreeNode*>&q,int N){
        int temp=INT_MIN+1;
        
        while(N--){
            TreeNode* curr=q.front();
            q.pop();

            // The Node shouldn't be Even , Shouldn't be Smaller than prev Node
            if(!(curr->val & 1) || !(temp<curr->val)) return false;
            temp=curr->val;

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }

        return true;
    }
    public:
    bool isEvenOddTree(TreeNode* root){
        queue<TreeNode*>q;

        q.push(root);
        bool flag=true;

        while(!q.empty()){
            int N=q.size();
            if(flag){
                if(checkOdd(q,N)==false) return false;
            }
            else{
                if(checkEven(q,N)==false) return false;
            }
            flag=!flag;
        }
        return true;
    }
};
class DFS{
    vector<int>levelPrev;
    bool solve(TreeNode* root,int level){
        if(!root) return true;
        
        if((level%2 == 0 && root->val%2 == 0) || (level%2 != 0 && root->val%2 != 0)){
            return false;
        }
        
        if(level>=levelPrev.size()){
            levelPrev.resize(level+1);
        }

        if(levelPrev[level]!=0){
            // Already there is a value at this level
            if((level%2 == 0 && root->val <= levelPrev[level]) ||
               (level%2 != 0 && root->val >= levelPrev[level])){
                    return false;
               }
        }
        
        levelPrev[level]=root->val;
        
        return solve(root->left,level+1) && solve(root->right,level+1);
    }
    public:
    bool isEvenOddTree(TreeNode* root){
        return solve(root,0);
    }
};
/*
-> Example 1:
Input: root = [1,10,4,3,null,7,9,12,8,6,null,null,2]
Output: true
:---------------------:
-> Example 2:
Input: root = [5,4,2,3,3,7]
Output: false
:---------------------:
-> Example 3:
Input: root = [5,9,1,3,5,7]
Output: false
*/