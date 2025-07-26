// LC - 589 - Easy - N-ary Tree Preorder Traversal
#include<iostream>
#include<vector>
using namespace std;
class Node{
public:
    int val;
    vector<Node*>children;
    Node(int _val){
        val=_val;
    }
    Node(int _val,vector<Node*>_children){
        val=_val;
        children=_children;
    }
};
class Tree{
    void solve(Node* root,vector<int>&ans){
        if(!root) return;

        ans.push_back(root->val);
        
        for(int i=0;i<root->children.size();i++){
            solve(root->children[i],ans);
        }
    }
    public:
    vector<int> preorder(Node* root){
        vector<int>ans;

        solve(root,ans);
        return ans;
    }
};
/*
-> Example 1:
Input: root = [1,null,3,2,4,null,5,6]
Output: [1,3,5,6,2,4]
:---------------------------:
-> Example 2:
Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [1,2,3,6,7,11,14,4,8,12,5,9,13,10]
*/