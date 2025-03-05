// ***** IMP *****
// AVL trees - self balancing binary search trees (BSTs)
// For every node in the tree, the balance factor (difference in heights of left and right subtrees) must be -1, 0, or 1.
// Rotations (to maintain balance):
// Single Right Rotation (LL Case).
// Single Left Rotation (RR Case).
// Left-Right Rotation (LR Case).
// Right-Left Rotation (RL Case).
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    int height;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        this->height=1;
        this->left=NULL;
        this->right=NULL;
    }
};
int getHeight(Node* root){
    if(!root) return 0;
    return root->height;
}
int getBalancingFactor(Node* root){
    if(!root) return 0;
    return getHeight(root->left)-getHeight(root->right);
}
// Right rotation -> LL Case
/*       0root
        0y
       0
        */
Node* rightRotate(Node* root){
    Node* y=root->left;
    Node* z=y->right;
    // Doing rotation
    y->right=root;
    root->left=z;
    // Update heights
    root->height=max(getHeight(root->left),getHeight(root->right))+1;
    y->height=max(getHeight(y->left),getHeight(y->right))+1;
    // returning new root
    return y; 
}
// Left rotation -> RR Case
/*       0root
            0y
                0
        */
Node* leftRotate(Node* root){
    Node* y=root->right;
    Node* z=y->left;
    // doing rotation
    y->left=root;
    root->right=z;
    // update h
    root->height=max(getHeight(root->left),getHeight(root->right))+1;
    y->height=max(getHeight(y->left),getHeight(y->right))+1;
    // return new root
    return y;
}
Node* insert(Node* root,int data){
    // Step 1: Standard BST insertion
    if(!root) return new Node(data);
    if(data<root->data) root->left=insert(root->left,data);
    else if(data>root->data) root->right=insert(root->right,data);
    else root;
    // Step 2: Update height of the tree after insertion
    root->height=max(getHeight(root->left),getHeight(root->right))+1;
    // Step 3: Get the balance factor
    int balance=getBalancingFactor(root);
    // Step 4: Balance the tree
    // (A) LL Case
    if(balance>1 && data<root->left->data){
        return rightRotate(root);
    }
    // (B) RR Case
    if(balance<-1 && data>root->right->data){
        return leftRotate(root);
    }
    // (C) LR Case
    if(balance>1 && data>root->left->data){
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    // (D) RL Case
    if(balance<-1 && data<root->right->data){
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
Node* getMin(Node* root){
    while(root->left){
       root=root->left;
    }
    return root;
}
Node* deleteInAVL(Node* root,int data){
    if(root==NULL){
        return root;
    }
    // Standard BST deletion
    if(data<root->data){
        root->left=deleteInAVL(root->left,data);
    } else if(data>root->data){
        root->right=deleteInAVL(root->right,data);
    } else{
        // Nodes with 0 or 1 child
        if(!root->left || !root->right){
            Node* temp=root->left?root->left:root->right;
            // NO CHILD CASE
            if(!temp){
                temp=root;
                root=NULL;
            } else{ // 1 child
                *root=*temp;
            }
            delete temp;
        } else{
            // Nodes with 2 children
            // Getting inorder successor
            Node* temp=getMin(root->right);
            root->data=temp->data;
            // Deleting successor
            root->right=deleteInAVL(root->right,temp->data);
        }
    }
    if(!root){
        return root;
    }
    // updating h of root
    root->height=max(getHeight(root->left),getHeight(root->right))+1;

    int balance=getBalancingFactor(root);
    // Rotations
    // (A) LL Case
    if(balance>1 && getBalancingFactor(root->left)>=0){
        return rightRotate(root);
    }
    // (B) RR Case
    if(balance<-1 && getBalancingFactor(root->right)<=0){
        return leftRotate(root);
    }
    // (C) LR Case
    if(balance>1 && getBalancingFactor(root->left)<0){
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    // (D) RL Case
    if(balance<-1 && getBalancingFactor(root->right)<=0){
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
void printInOrder(Node* root){
    if(root==NULL){
        return;
    }
    printInOrder(root->left);
    cout<<root->data<<" ";
    printInOrder(root->right);
}
bool isBalanced(Node* root){
    if(root==NULL) return true;
    int lH=getHeight(root->left);
    int rH=getHeight(root->right);
    return abs(lH-rH)<=1 && isBalanced(root->left) && isBalanced(root->right);
}
int main(){
    Node* root=NULL;
    root=insert(root,20);
    root=insert(root,10);
    root=insert(root,30);
    root=insert(root,5);
    root=insert(root,2);
    root=insert(root,1);
    cout<<"Traversal:";
    printInOrder(root);
    cout<<endl;
    root=deleteInAVL(root,5);
    cout<<"Traversal:";
    printInOrder(root);
    return 0;
}