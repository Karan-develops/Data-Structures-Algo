// LC - 501 - Easy - Find Mode in Binary Search Tree
// 2 Approaches
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
};
class Solution1{
    unordered_map<int,int>mp;
    void solve(Node* root){
        if(!root) return;

        solve(root->left);
        mp[root->data]++;
        solve(root->right);
    }
    public:
    vector<int> findMode(Node* root){
        vector<int>ans;
        solve(root);
        int maxFreq=0;
        for(auto it:mp){
            if(it.second>maxFreq){
                maxFreq=it.second;
                ans.clear();
                ans.push_back(it.first);
            } else if(it.second==maxFreq){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
class Solution2{
    int currNum=0;
    int currFreq=0;
    int maxFreq=0;
    vector<int>ans;
    vector<int> dfs(Node* root){
        if(!root) return {};

        dfs(root->left);

        if(root->data==currNum) currFreq++;
        else{
            currNum=root->data;
            currFreq=1;
        }

        if(currFreq>maxFreq){
            ans.clear();
            maxFreq=currFreq;
        }
        if(currFreq==maxFreq){
            ans.push_back(root->data);
        }

        dfs(root->right);
    }
    public:
    vector<int> findMode(Node* root){
        dfs(root);
        return ans;
    }
};