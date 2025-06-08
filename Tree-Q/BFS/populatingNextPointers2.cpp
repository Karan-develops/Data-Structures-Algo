// LC - 117 - Medium - Populating Next Right Pointers in Each Node II
#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node* next;
};
class BFS{
    public:
    Node* connect(Node* root) {
        if(!root) return root;

        queue<Node*>q;
        q.push(root);
        Node* prev;

        while(!q.empty()){
            int N=q.size();
            prev=NULL;
            while(N--){
                Node* curr=q.front();
                q.pop();

                if(prev) prev->next=curr;

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);

                prev=curr;
            }
        }
        return root;
    }
};
/*
-> Example 1:
Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]
:-----------------------:
-> Example 2:
Input: root = []
Output: []
*/