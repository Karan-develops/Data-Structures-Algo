// Morris Traversal
// We can traverse without recursion with constant space
#include<iostream>
#include<vector>
using namespace std;
class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
};
class Morris{
    public:
    vector<int> inorderTraversal(TreeNode* root){
        vector<int>ans;

        TreeNode* curr=root;
        while(curr){
            if(!curr->left){
                ans.push_back(curr->data);
                curr=curr->right;
            } else{
                TreeNode* prev=curr->left;

                while(prev->right){
                    prev=prev->right;
                }

                prev->right=curr;
                TreeNode* temp=curr;
                curr=curr->left;
                temp->left=NULL;
            }
        }
        return ans;
    }
};