// GFG - Count the nodes at distance K from leaf
// 2 Approaches
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
};
class Solution{
    vector<vector<Node*>>paths;
    void solve(Node* root,vector<Node*>&temp){
        if(!root) return;
        
        temp.push_back(root);
        
        if(!root->left && !root->right){
            paths.push_back(temp);
        }
        
        solve(root->left,temp);
        solve(root->right,temp);
        
        temp.pop_back();
    }
    public:
    int printKDistantfromLeaf(Node* root,int k){
        vector<Node*>temp;
        solve(root,temp);
        
        unordered_set<Node*>ans;
        
        for(auto &path:paths){
            int n=path.size();
            if(n>k){
                ans.insert(path[n-k-1]);
            }
        }
        return ans.size();
    }
};
class Solution2{
    public:
    void solve(Node* root,int level,unordered_set<Node*>&ans,vector<Node*>&path,int &k){
        if(!root) return;
        
        path.push_back(root);
        if(!root->left && !root->right){
            if(level-k>=0){
                ans.insert(path[level-k]);
            }
        }
        solve(root->left,level+1,ans,path,k);
        solve(root->right,level+1,ans,path,k);
        path.pop_back();
    }
    int printKDistantfromLeaf(Node* root,int k){
        vector<Node*>path;
        unordered_set<Node*>ans;
    	
    	solve(root,0,ans,path,k);
    	return ans.size();
    }
};