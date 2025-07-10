// LC - 2096 - Medium - Step-By-Step Directions From a Binary Tree Node to Another
// 3 Approaches - Graph - LCA - Optimized LCA
// Good Q*
#include<iostream>
#include<unordered_map>
#include<queue>
#include<unordered_set>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
};
class Approach1{
    void getAdj(TreeNode* root,unordered_map<int,vector<pair<int,char>>>&adj){
        if(!root) return;

        if(root->left){
            adj[root->val].push_back({root->left->val,'L'});
            adj[root->left->val].push_back({root->val,'U'});
            getAdj(root->left,adj);
        }
        if(root->right){
            adj[root->val].push_back({root->right->val,'R'});
            adj[root->right->val].push_back({root->val,'U'});
            getAdj(root->right,adj);
        }
    }
    public:
    string getDirections(TreeNode* root,int startValue,int destValue){
        unordered_map<int,vector<pair<int,char>>>adj;
        getAdj(root,adj);

        queue<pair<int,string>>q;
        unordered_set<int>visited;

        q.push({startValue,""});
        visited.insert(startValue);

        while(!q.empty()){
            auto [curr,path]=q.front();
            q.pop();

            if(curr==destValue) return path;

            for(auto &[ngbr,dir]:adj[curr]){
                if(!visited.count(ngbr)){
                    visited.insert(ngbr);
                    q.push({ngbr,path+dir});
                }
            }
        }
        return "";
    }
};
class Approach2{
    TreeNode* LCA(TreeNode* root,int &src,int &dest){
        if(!root) return NULL;

        if(root->val==src || root->val==dest){
            return root;
        }

        TreeNode* l=LCA(root->left,src,dest);
        TreeNode* r=LCA(root->right,src,dest);

        if(l && r) return root;

        return l?l:r;
    }
    bool findPath(TreeNode* lca,int &target,string &path){
        if(!lca) return false;

        // Found Target
        if(lca->val==target) return true;

        path.push_back('L');
        if(findPath(lca->left,target,path)==true){
            return true;
        }
        path.pop_back();

        path.push_back('R');
        if(findPath(lca->right,target,path)==true){
            return true;
        }
        path.pop_back();

        // Not Found
        return false;
    }
    public:
    string getDirections(TreeNode* root,int startValue,int destValue){
        TreeNode* lca=LCA(root,startValue,destValue);

        string lcaToSrc="";
        string lcaToDest="";

        findPath(lca,startValue,lcaToSrc);
        findPath(lca,destValue,lcaToDest);

        string ans="";
        // Up for start to LCA
        for(int i=0;i<lcaToSrc.length();i++){
            ans.push_back('U');
        }

        ans+=lcaToDest;

        return ans;
    }
};
class Approach3{
    bool findPath(TreeNode* lca,int &target,string &path){
        if(!lca) return false;

        // Found Target
        if(lca->val==target) return true;

        path.push_back('L');
        if(findPath(lca->left,target,path)==true){
            return true;
        }
        path.pop_back();

        path.push_back('R');
        if(findPath(lca->right,target,path)==true){
            return true;
        }
        path.pop_back();

        // Not Found
        return false;
    }
    public:
    string getDirections(TreeNode* root,int startValue,int destValue){
        
        string rootToSrc="";
        string rootToDst="";

        findPath(root,startValue,rootToSrc);
        findPath(root,destValue,rootToDst);

        // Eliminate same nodes
        int l=0;
        while(l<rootToSrc.length() && l<rootToDst.length() && rootToSrc[l]==rootToDst[l]){
            l++;
        }

        string ans="";
        //Add "U"
        for(int i=0;i<rootToSrc.length()-l;i++){
            ans.push_back('U');
        }

        for(int i=l;i<rootToDst.length();i++){
            ans.push_back(rootToDst[i]);
        }

        return ans;
    }
};