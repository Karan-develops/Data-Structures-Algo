// LC - 199 - Medium - Binary Tree Right Side View
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
};
class Solution{
    vector<int> rightSideView(Node* root){
        if(!root) return {};
        vector<int>ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int N=q.size();
            Node* rightMostNode=NULL;
            while(N--){
                rightMostNode=q.front();
                q.pop();

                if(rightMostNode->left) q.push(rightMostNode->left);
                if(rightMostNode->right) q.push(rightMostNode->right);
            }
            ans.push_back(rightMostNode->data);
        }
        return ans;
    }
};