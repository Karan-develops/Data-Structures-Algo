// LC - 968 - HARD - Binary Tree Cameras
// Good Q*
// 2 Approaches
#include<iostream>
#include<unordered_set>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
};
class Tree1{
    int ans=0;
    unordered_set<TreeNode*>covered;
    void dfs(TreeNode* root,TreeNode* parent){
        if(!root) return;
        
        dfs(root->left,root);
        dfs(root->right,root);
        
        if((parent==NULL && covered.find(root)==covered.end()) ||
           (covered.find(root->left)==covered.end()) || 
           (covered.find(root->right)==covered.end())){
            ans++;
            
            // Put Camera
            covered.insert(parent);
            covered.insert(root);
            covered.insert(root->left);
            covered.insert(root->right);
        }
    }
    public:
    int minCameraCover(TreeNode* root){
        // We put cameras on a node if
        /*
            -It doesn't have a camera
            -It's parent doesn't have a camera
            -It's left and right child doesn't have a camera
            i.e. it's not covered by any camera
            
            Note: I will never assign camera to a leaf node.
			It will be better if I assign camera to that leaf's
			parent node,because parent will cover both its
			child as well it's own parent as well.
        */
        covered.clear();
        
        // Because for leaf node, (covered.find(root->left) == covered.end()) is true
        // But I don't want to assign camera here at leaf
        covered.insert(NULL);
        ans=0;
        
        dfs(root,NULL);
        return ans;
    }
};
//Approach-2 (Using status of nodes : From bottom to up)
class Solution{
public:
    int cameras=0;
    const int needCamera=-1,covered=0,haveCamera=1;
    int dfs(TreeNode* root){
        if(!root){
            return covered;
            /*
                So that leaf doesn't install camera on it
                Note: I will never assign camera to a leaf node.
                It will be better if I assign camera to that leaf's
                parent node,because parent will cover both its
                child as well it's own parent as well.  
            */
        }
        
        int l=dfs(root->left);
        int r=dfs(root->right);
        
        if(l==0 && r==0){
            /*
                I will tell my parent to cover me because my
                children are already covered. Installing camera
                on me will not benefecial. Let my parent do that
                because my parent will cover me, my brother and
                my grandfather as well 
            */
            return needCamera;// I need my parent to cover me by a camera on them
        }
        
        if(l==-1 || r==-1){
            /*
                if any of my child wants me to put a camera on me,
                I will have to put a camera on my self. AND i will tell
                my parent that I have a camera. Not to worry
            */
            cameras++;
            return haveCamera;
        }
        
        if(l==1 || r==1){
            /*
                If any of my child has a camera, I will
                be covered as well. SO I will tell my parent
                that I am covered
            */
            return covered;
        }
        
		// Don't worry about this case. control will never reach here
        return -1;
    }
    int minCameraCover(TreeNode* root){
        /*
            status code  : what does that mean
            
            -1 : I need a camera to be covered
             0 : covered by either(child or parent)
             1 : I have a camera so I am covered as well
                (but if my brother needs a camera my parent will
                install camera on it)
        */
        cameras=0;
        int status_of_root=dfs(root);

        /*
         Wait Wait, don't directly return cameras here.
         Just one thing you missed. Take a case as shown below
                    root
                    / \
                   /   \
                  NULL NULL
         NULL returns 1 and 1, i.e. they are covered.
         So, root will tell it's parent to install a camera and it will
         return -1. But root has no parent. So this case will be missed.
         So, check the returned value of dfs here and see if it's -1
         then add one camera and then return cameras
        */

        if(status_of_root==needCamera) cameras++;
        return cameras;
    }
};