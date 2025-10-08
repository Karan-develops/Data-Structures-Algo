// LC - 889 - Medium - Construct Binary Tree from Preorder and Postorder Traversal
#include<iostream>
#include<vector>
#include<unordered_map>
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
public:
    unordered_map<int,int>mp;
    TreeNode* solve(vector<int>&preorder,vector<int>&postorder,int preStart,int postStart,int preEnd){
        if(preStart>preEnd){
            return NULL;
        }

        TreeNode* root=new TreeNode(preorder[preStart]);
        if(preStart==preEnd) return root;
        
        // root of left subtree
        int nextRoot=preorder[preStart+1];
        
        int j=mp[nextRoot];
        int nodeCount=j-postStart+1;
        
        root->left=solve(preorder,postorder,preStart+1,postStart,preStart+nodeCount);
        root->right=solve(preorder,postorder,preStart+nodeCount+1,j+1,preEnd);
        
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>&preorder,vector<int>&postorder){
        int n=preorder.size();

        for(int i=0;i<n;i++){
            mp[postorder[i]]=i;
        }
        
        return solve(preorder,postorder,0,0,n-1);
    }
};
int main(){
    // Output: [1,2,3,4,5,6,7]
    vector<int>preorder={1,2,4,5,3,6,7},postorder={4,5,2,6,7,3,1};
    // Output: [1]
    vector<int>preorder2={1},postorder2={1};
    return 0;
}