// LC - 2196 - Medium - Create Binary Tree From Descriptions
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};
class Tree{
    public:
    TreeNode* createBinaryTree(vector<vector<int>>&descriptions){
        unordered_map<int,TreeNode*>mp;
        unordered_set<int>childSet;

        for(auto &vec:descriptions){
            int parent=vec[0];
            int child=vec[1];
            int isLeft=vec[2];

            if(mp.find(parent)==mp.end()){
                mp[parent]=new TreeNode(parent);
            }

            if(mp.find(child)==mp.end()){
                mp[child]=new TreeNode(child);
            }

            if(isLeft == 1){
                mp[parent]->left=mp[child];
            } else{
                mp[parent]->right=mp[child];
            }
            childSet.insert(child);
        }

        // Find the root
        for(auto &vec:descriptions){
            int parent=vec[0];
            if(childSet.find(parent)==childSet.end()){
                return mp[parent];
            }
        }
        return NULL;
    }
};
int main(){
    // Output: [50,20,80,15,17,19]
    vector<vector<int>>descriptions={{20,15,1},{20,17,0},{50,20,1},{50,80,0},{80,19,1}};
    // Output: [1,2,null,null,3,4]
    vector<vector<int>>descriptions2={{1,2,1},{2,3,0},{3,4,1}};
    return 0;
}