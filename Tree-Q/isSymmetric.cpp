// LC - 101 - Easy - Symmetric Tree
#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* left;
    Node* right;
};
class Solution {
    bool solve(Node* leftSide,Node* rightSide){
        if(leftSide==NULL && rightSide==NULL) return true;
        if(leftSide==NULL || rightSide==NULL) return false;
        return ((leftSide->val==rightSide->val) && 
        solve(leftSide->left,rightSide->right) && 
        solve(leftSide->right,rightSide->left));
    }
    public:
    bool isSymmetric(Node* root) {
        return solve(root->left,root->right);
    }
};
int main(){
    Solution sol;
    // IP Tree [1,2,2,3,4,4,3]
    // sol.isSymmetric(tree);
    return 0;
}