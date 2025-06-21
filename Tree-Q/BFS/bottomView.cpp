// GFG - Bottom View of Binary Tree
#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
};
class BFS{
    public:
    vector<int> bottomView(Node *root){
        if(!root) return {};
        
        queue<pair<Node*,int>>q;
        map<int,int>mp;
        vector<int>ans;
        
        q.push({root,0});
        
        while(!q.empty()){
            Node* node=q.front().first;
            int dist=q.front().second;
            q.pop();
            
            mp[dist]=node->data;
            
            if(node->left) q.push({node->left,dist-1});
            if(node->right) q.push({node->right,dist+1});
        }
        
        for(auto &it:mp){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};
/*
-> Input: root[] = [1, 3, 2]
Output: [3 1 2]
:------------------:
-> Input: root[] = [10, 20, 30, 40, 60]
Output: [40 20 60 30]
*/