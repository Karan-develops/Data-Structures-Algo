// LC - 2385 - Medium - Amount of Time for Binary Tree to Be Infected
// 2 Approaches - BFS - DFS
#include<iostream>
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
    void getAdj(TreeNode* root,unordered_map<int,vector<int>>&adj,int parent){
        if(!root) return;

        if(parent!=-1) adj[parent].push_back(root->val);

        if(root->left){
            adj[root->left->val].push_back(root->val);
            getAdj(root->left,adj,root->val);
        }
        if(root->right){
            adj[root->right->val].push_back(root->val);
            getAdj(root->right,adj,root->val);
        }
    }
    public:
    int amountOfTime(TreeNode* root,int start){
        unordered_map<int,vector<int>>adj;
        getAdj(root,adj,-1);

        queue<int>q;
        unordered_set<int>visited;

        visited.insert(start);
        q.push(start);
        int ans=0;

        while(!q.empty()){
            int N=q.size();
            while(N--){
                int node=q.front();
                q.pop();

                for(int &ngbr:adj[node]){
                    if(!visited.count(ngbr)){
                        visited.insert(ngbr);
                        q.push(ngbr);
                    }
                }
            }
            ans++;
        }
        return ans-1;
    }
};
class DFS{
    int ans=INT_MIN;
    int solve(TreeNode* root,int start){
        if(!root) return 0;

        int LH=solve(root->left,start);
        int RH=solve(root->right,start);

        if(root->val==start){
            ans=max(LH,RH);
            return -1;
        } else if(LH>=0 && RH>=0){
            return max(LH,RH)+1;
        } else {
            int d=abs(LH)+abs(RH);
            ans=max(ans,d);

            return min(LH,RH)-1;
        }
        return 0;
    }
    public:
    int amountOfTime(TreeNode* root,int start){
        ans=INT_MIN;
        solve(root,start);

        return ans;
    }
};
/*
-> Example 1:
Input: root = [1,5,3,null,4,10,6,9,2], start = 3
Output: 4
:------------------------------:
-> Example 2:
Input: root = [1], start = 1
Output: 0
*/