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
    cout<<"Enter data:";
    cin>>data;
    if(data==-1) return NULL;
    Node* root=new Node(data);
    cout<<"Enter data for left part:";
    root->left=buildTree();
    cout<<"Enter data for right part";
    root->right=buildTree();
    return root;
}
bool kthAncestor(Node* &root,int &k,int &p){
    if(root==NULL) return false;
    if(root->data==p) return true;
    bool leftAns=kthAncestor(root->left,k,p);
    bool rightAns=kthAncestor(root->right,k,p);
    if(leftAns||rightAns) k--;
    if(k==0){
        cout<<"Answer:"<<root->data<<endl;
        k=-1;
    }
    return leftAns||rightAns;
}
int main(){
    Node* root=NULL;
    root=buildTree();
    int k=1,p=4;
    bool found=kthAncestor(root,k,p);
    if(found) cout<<"Yes";
    else cout<<"NO";
    return 0;
}