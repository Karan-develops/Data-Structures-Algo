// LC - 1530 - Medium - Number of Good Leaf Nodes Pairs
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
};
class BFS{
    void makeGraph(TreeNode* root,TreeNode* prev,unordered_map<TreeNode*,vector<TreeNode*>>&adj,unordered_set<TreeNode*>&leafSet){
        if(!root) return;

        if(!root->left && !root->right){
            leafSet.insert(root);
        }

        if(prev!=NULL){
            adj[root].push_back(prev);
            adj[prev].push_back(root);
        }

        makeGraph(root->left,root,adj,leafSet);
        makeGraph(root->right,root,adj,leafSet);
    }
    public:
    int countPairs(TreeNode* root,int distance){
        unordered_map<TreeNode*,vector<TreeNode*>>adj;
        unordered_set<TreeNode*>leafSet;

        makeGraph(root,NULL,adj,leafSet);

        int ans=0;

        for(auto &leaf:leafSet){
            queue<TreeNode*>q;
            unordered_set<TreeNode*>visited;
            q.push(leaf);
            visited.insert(leaf);

            // Only go till level <= distance
            for(int level=0;level<=distance;level++){
                int N=q.size();
                while(N--){
                    TreeNode* curr=q.front();
                    q.pop();

                    if(curr!=leaf && leafSet.count(curr)){ 
                        ans++;
                    }

                    for(auto &ngbr:adj[curr]){
                        if(!visited.count(ngbr)){
                            q.push(ngbr);
                            visited.insert(ngbr);
                        }
                    }
                }
            }
        }
        return ans/2;
    }
};