// LC - 993 - Medium - Cousins in Binary Tree
#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int val;
    Node* left;
    Node* right;
};
bool isCousins(Node* root,int x,int y){
    if(!root->left || !root->right) return false;
    
    queue<pair<Node*,Node*>>q;
    q.push({root,NULL});

    while(!q.empty()){
        int N=q.size();
        Node* parentX=NULL;
        Node* parentY=NULL;
        while(N--){
            Node* currNode=q.front().first;
            Node* parentNode=q.front().second;
            q.pop();

            if(currNode->val==x) parentX=parentNode;
            if(currNode->val==y) parentY=parentNode;

            if(currNode->left) q.push({currNode->left,currNode});
            if(currNode->right) q.push({currNode->right,currNode});
        }
        if(parentX && parentY) return parentX!=parentY;
        if(parentX || parentY) return false;
    }
    return false;
}
int main(){
    /*
    Input: root = [1,2,3,4], x = 4, y = 3
    Output: false
    Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
    Output: true
    Input: root = [1,2,3,null,4], x = 2, y = 3
    Output: false
    */
   return 0;
}