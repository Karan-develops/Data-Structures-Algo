// Tree traversals
// DFS -> Inorder, preorder & postorder
// BFS -> Level order
#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
Node* buildTree(){
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    Node* root=new Node(data);
    cout<<"Enter data in left of "<<data<<":";
    root->left=buildTree();
    cout<<"Enter data in right of "<<data<<":";
    root->right=buildTree();
    return root;
}
void inOrderT(Node* &root){
    if(root==NULL){
        return;
    }
    inOrderT(root->left);
    cout<<root->data<<" ";
    inOrderT(root->right);
    return;
}
void preOrderT(Node* &root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrderT(root->left);
    preOrderT(root->right);
    return;
}
void postOrderT(Node* &root){
    if(root==NULL){
        return;
    }
    postOrderT(root->left);
    postOrderT(root->right);
    cout<<root->data<<" ";
    return;
}
void levelOrder(Node* &root){
    if(root==NULL){
        return;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* currNode=q.front();
        q.pop();
        cout<<currNode->data<<" ";
        if(currNode->left) q.push(currNode->left);
        if(currNode->right) q.push(currNode->right);
    }
}
int main(){
    Node* root=buildTree();
    cout<<"InOrder:";
    inOrderT(root);
    cout<<endl;
    cout<<"PreOrder:";
    preOrderT(root);
    cout<<endl;
    cout<<"PostOrder:";
    postOrderT(root);
    cout<<endl;
    cout<<"Level Order:";
    levelOrder(root);
    return 0;
}