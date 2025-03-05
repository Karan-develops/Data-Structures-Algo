// Insertion
/*#include<iostream>
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
void printInOrder(Node* &root){
    if(root==NULL){
        return;
    }
    printInOrder(root->left);
    cout<<root->data<<" ";
    printInOrder(root->right);
    return;
}
Node* insert(Node* &root,int data){
    if(root==NULL){
        return new Node(data);
    }
    if(data<root->data) root->left=insert(root->left,data);
    else if(data>root->data) root->right=insert(root->right,data);
    return root;
}
bool search(Node* &root,int data){
    if(root==NULL){
        return false;
    }
    if(root->data==data) return true;
    else if(data<root->data) return search(root->left,data);
    else return search(root->right,data);
}
int main(){
    Node* root=NULL;
    root=insert(root,50);
    root=insert(root,30);
    root=insert(root,70);
    root=insert(root,20);
    root=insert(root,40);
    root=insert(root,60);
    root=insert(root,80);
    cout<<"Inorder:";
    printInOrder(root);
    cout<<endl;
    if(search(root,20)) cout<<"Found";
    else cout<<"Not Found";
    return 0;
}
*/
// Deletion
/* Deleting a node from a BST involves three cases:
1) Node has no children (Leaf Node): Simply remove the node.
2) Node has one child: Replace the node with its child.
3) Node has two children: Replace the node with its inorder successor (smallest node in the right subtree).*/
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
void printInorder(Node* root){
    if(root==NULL){
        return;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
    return;
}
Node* insert(Node* &root,int data){
    if(root==NULL){
        return new Node(data);
    }
    if(data<root->data) root->left=insert(root->left,data);
    else if(data>root->data) root->right=insert(root->right,data);
    return root; 
}
Node* findMin(Node* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}
Node* deleteNode(Node* &root,int data){
    if(root==NULL){
        return root;
    }
    if(data<root->data) root->left=deleteNode(root->left,data);
    else if(data>root->data) root->right=deleteNode(root->right,data);
    else{
        if(root->left==NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        } else if(root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        // Node has 2 children
        Node* temp=findMin(root->right);
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data);
    }
    return root;
}
int main(){
    Node* root=NULL;
    root=insert(root,50);
    root=insert(root,30);
    root=insert(root,70);
    root=insert(root,20);
    root=insert(root,40);
    root=insert(root,60);
    root=insert(root,80);
    cout<<"Inorder:";
    printInorder(root);
    cout<<endl;
    root=deleteNode(root,40);
    cout<<"Inorder:";
    printInorder(root);
    cout<<endl;
    return 0;
}