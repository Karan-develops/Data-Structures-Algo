// LC - 106 - Medium - Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode* solve(vector<int>&inorder,vector<int>&postorder,int inStart,int inEnd,int postStart,int postEnd){
        if(inStart>inEnd) return NULL;

        TreeNode* root=new TreeNode(postorder[postEnd]);

        int i=inStart;
        for(;i<=inEnd;i++){
            if(inorder[i]==postorder[postEnd]){
                break;
            }
        }

        int leftSize=i-inStart;
        int rightSize=inEnd-i;

        root->left=solve(inorder,postorder,inStart,i-1,postStart,postStart+leftSize-1);
        root->right=solve(inorder,postorder,i+1,inEnd,postEnd-rightSize,postEnd-1);

        return root;
    }
    public:
    TreeNode* buildTree(vector<int>&inorder,vector<int>&postorder){
        int n=inorder.size();

        int inStart=0,inEnd=n-1;
        int postStart=0,postEnd=n-1;

        return solve(inorder,postorder,inStart,inEnd,postStart,postEnd);
    }
};
int main(){
    // Output: [3,9,20,null,null,15,7]
    vector<int>inorder={9,3,15,20,7},postorder={9,15,7,20,3};
    // Output: [-1]
    vector<int>inorder2={-1},postorder2={-1};
    return 0;
}