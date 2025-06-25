// LC - 623 - Medium - Add One Row to Tree
// BFS - DFS
#include<iostream>
#include<queue>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};
class Tree{
    TreeNode* add(TreeNode* root,int val,int depth,int curr){
        if(!root) return NULL;
        
        if(curr==depth-1){
            TreeNode* lTemp=root->left;
            TreeNode* rTemp=root->right;
            
            root->left=new TreeNode(val);
            root->right=new TreeNode(val);
            root->left->left=lTemp;
            root->right->right=rTemp;
            
            return root;
        }
        
        root->left=add(root->left,val,depth,curr+1);
        root->right=add(root->right,val,depth,curr+1);
        
        return root;
    }
    public:
    TreeNode* addOneRowBFS(TreeNode* root,int val,int depth){
        if(depth==1){
            TreeNode* newRoot=new TreeNode(val);
            newRoot->left=root;
            return newRoot;
        }
        
        queue<TreeNode*>q;

        q.push(root);
        int level=0;
        bool rowAdded=false;

        while(!q.empty()){
            int N=q.size();
            level++;
            while(N--){
                TreeNode* curr=q.front();
                q.pop();

                TreeNode* tempL=curr->left;
                TreeNode* tempR=curr->right;

                if(level==depth-1){
                    curr->left=new TreeNode(val);
                    curr->right=new TreeNode(val);

                    curr->left->left=tempL;
                    curr->right->right=tempR;
                    rowAdded=true;
                }

                if(tempL) q.push(tempL);
                if(tempR) q.push(tempR);
            }
            if(rowAdded) break;
        }
        return root;
    }
    TreeNode* addOneRowDFS(TreeNode* root,int val,int depth){
        if(depth==1){
            TreeNode* newRoot=new TreeNode(val);
            newRoot->left=root;
            return newRoot;
        }
        return add(root,val,depth,1);
    }
};
/*
-> Example 1:
Input: root = [4,2,6,3,1,5], val = 1, depth = 2
Output: [4,1,1,2,null,null,6,3,1,5]
:----------------------:
-> Example 2:
Input: root = [4,2,null,3,1], val = 1, depth = 3
Output: [4,2,null,1,1,3,null,null,1]
*/