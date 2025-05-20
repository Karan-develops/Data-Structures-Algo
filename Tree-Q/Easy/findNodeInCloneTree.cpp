// LC - 1379 - Easy - Find a Corresponding Node of a Binary Tree in a Clone of That Tree
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
    Node* getTargetCopy(Node* original, Node* cloned, Node* target) {
        int targetVal=target->data;
        queue<Node*>q;
        q.push(cloned);

        while(!q.empty()){
            Node* currNode=q.front();
            q.pop();

            if(currNode->data==targetVal) return currNode;

            if(currNode->left) q.push(currNode->left);
            if(currNode->right) q.push(currNode->right);
        }
        return NULL;
    }
};
/*
Example 1:
Input: tree = [7,4,3,null,null,6,19], target = 3
Output: 3
Example 2:
Input: tree = [7], target =  7
Output: 7
Example 3:
Input: tree = [8,null,6,null,5,null,4,null,3,null,2,null,1], target = 4
Output: 4
*/