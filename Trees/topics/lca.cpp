// Lowest Common Ancestor
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
Node* LCA(Node* root,int p,int q){
    if(root==NULL || root->data==p || root->data==q){
        return root;
    }
    Node* left=LCA(root->left,p,q);
    Node* right=LCA(root->right,p,q);
    if(left!=NULL && right!=NULL) return root;
    return left!=NULL?left:right;
}
int main(){
    Node* root=NULL;
    int p=5,q=7;
    root=buildTree();
    Node* ans=LCA(root,p,q);
    cout<<ans->data;
    return 0;
}