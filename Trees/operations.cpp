#include<iostream>
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
    if(data==-1) return NULL;
    Node* root=new Node(data);
    cout<<"Enter data in left of "<<data<<":";
    root->left=buildTree();
    cout<<"Enter data in right of "<<data<<":";
    root->right=buildTree();
    return root;
}
Node* insert(Node* root,int data){
    if(root==NULL){
        return new Node(data);
    }
    if(data<root->data) root->left=insert(root->left,data);
    else if(data>root->data) root->right=insert(root->right,data);
    return root;
}
// Height of Tree
int height(Node* root){
    if(root==NULL){
        return -1;
    }
    int lH=height(root->left);
    int rH=height(root->right);
    return 1+max(lH,rH);
}
// Is tree balanced
bool isBalanced(Node* root){
    if(root==NULL) return true;
    int lH=height(root->left);
    int rH=height(root->right);
    return abs(lH-rH)<=1 && isBalanced(root->left) && isBalanced(root->right);
}
// Diameter of Tree
int diameter(Node* root,int &dia){
    if(root==NULL){
        return -1;
    }
    int lH=diameter(root->left,dia);
    int rH=diameter(root->right,dia);
    dia=max(dia,lH+rH+2);
    return 1+max(lH,rH);
}
// Check Symmetry
bool isMirror(Node* root1,Node* root2){
    if(root1==NULL && root2==NULL) return true;
    if(root1==NULL || root2==NULL) return false;
    return (root1->data==root2->data) && isMirror(root1->left,root2->right) && isMirror(root1->right,root2->left);
}
bool isSymmetric(Node* root){
    if(root==NULL) return true;
    return isMirror(root->left,root->right);
}
int main(){
    Node* root=NULL;
    // root=buildTree();
    root=insert(root,50);
    root=insert(root,30);
    root=insert(root,70);
    root=insert(root,20);
    root=insert(root,40);
    root=insert(root,60);
    root=insert(root,80);
    int ans=height(root);
    cout<<"H:"<<ans<<endl;
    if(isBalanced(root)) cout<<"Balanced";
    else cout<<"Not Balanced";
    cout<<endl;
    int dm=0;
    diameter(root,dm);
    cout<<"Diameter:"<<dm<<endl;

    return 0;
}