// LC - 1161 - Medium - Maximum Level Sum of a Binary Tree
#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
};
class Solution {
    public:
    int maxLevelSum(Node* root) {
        if(!root) return 0;
        queue<Node*>q;
        q.push(root);
        int ans=0,level=1;
        int maxSum=INT_MIN;
        while(!q.empty()){
            int N=q.size();
            int currSum=0;
            while(N--){
                Node* currNode=q.front();
                q.pop();

                currSum+=currNode->data;

                if(currNode->left) q.push(currNode->left);
                if(currNode->right) q.push(currNode->right);
            }
            if(currSum>maxSum){
                maxSum=currSum;
                ans=level;
            }
            level++;
        }
        return ans;
    }
};