// LC - 530 - Easy - Minimum Absolute Difference in BST
// 2 Approaches
#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
};
class Solution1{
    void solve(Node* root,vector<int>&nums){
        if(!root) return;

        solve(root->left,nums);
        nums.push_back(root->data);
        solve(root->right,nums);
    }
    public:
    int getMinimumDifference(Node* root){
        vector<int>nums;
        solve(root,nums);
        int min_Diff=INT_MAX;
        for(int i=0;i<nums.size()-1;i++){
            min_Diff=min(min_Diff,abs(nums[i]-nums[i+1]));
        }
        return min_Diff;
    }
};
// We can also make prev global
class Solution2{
    int min_Diff=INT_MAX;
    void solve(Node* root,Node* &prev){
        if(!root) return;

        solve(root->left,prev);

        if(prev){
            min_Diff=min(min_Diff,root->data-prev->data);
        }
        prev=root;

        solve(root->right,prev);
    }
    public:
    int getMinimumDifference(Node* root){

    }
};