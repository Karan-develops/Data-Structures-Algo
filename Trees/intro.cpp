// Everything is in CHATGPT'S HISTORY
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
void printTree(Node* &root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);
    return;
}
Node* buildTree(){
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    Node* root=new Node(data);
    cout<<"Enter data in left of "<<data<<":"<<endl;
    root->left=buildTree();
    cout<<"Enter data in right of "<<data<<":"<<endl;
    root->right=buildTree();
    return root;
}
int main(){
    Node* tree=buildTree();
    printTree(tree);
    return 0;
}