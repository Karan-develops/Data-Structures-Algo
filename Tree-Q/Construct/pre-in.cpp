// LC - 105 - Medium - Construct Binary Tree from Preorder and Inorder Traversal
#include<iostream>
#include<vector>
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
    TreeNode* solve(vector<int>&preorder,vector<int>&inorder,int start,int end,int &idx){
        if(start>end) return NULL;

        int i=start;
        // Store here to make node bcoz of idx++
        int val=preorder[idx];
        
        for(;i<=end;i++){
            if(inorder[i]==val) break;
        }
        
        idx++;
        
        TreeNode* root=new TreeNode(val);
        
        root->left=solve(preorder,inorder,start,i-1,idx);
        root->right=solve(preorder,inorder,i+1,end,idx);
        
        return root;
    }
    public:
    TreeNode* buildTree(vector<int>&preorder,vector<int>&inorder){
        int n=preorder.size();
        int idx=0;

        return solve(preorder,inorder,0,n-1,idx);
    }
};
int main(){
    // Output: [3,9,20,null,null,15,7]
    vector<int>preorder={3,9,20,15,7},inorder={9,3,15,20,7};
    // Output: [-1]
    vector<int>preorder2={-1},inorder2={-1};
    return 0;
}