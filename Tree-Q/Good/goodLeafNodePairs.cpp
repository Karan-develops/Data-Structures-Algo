// LC - 1530 - Medium - Number of Good Leaf Nodes Pairs
// BFS in graph-conversion
#include<iostream>
#include<vector>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
};
class DFS{
    vector<int> solve(TreeNode* root,int distance,int &ans){
        if(!root) return {0};

        if(!root->left && !root->right){
            return {1};
        }

        auto left_d=solve(root->left,distance,ans);
        auto right_d=solve(root->right,distance,ans);

        for(int &l:left_d){
            for(int &r:right_d){
                if((l!=0 && r!=0) && l+r<=distance){
                    ans++;
                }
            }
        }

        vector<int>curr_d;
        for(int &ld:left_d){
            if(ld!=0 && ld+1<=distance){
                curr_d.push_back(ld+1);
            }
        }

        for(int &rd:right_d){
            if(rd!=0 && rd+1<=distance){
                curr_d.push_back(rd+1);
            }
        }
        return curr_d;
    }
    public:
    int countPairs(TreeNode* root,int distance){
        int ans=0;
        solve(root,distance,ans);

        return ans;
    }
};