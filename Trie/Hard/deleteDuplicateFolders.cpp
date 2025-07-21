// LC - 1948 - HARD - Delete Duplicate Folders in System
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Trie{
    struct TrieNode{
        string name;
        string subFolder;
        unordered_map<string,TrieNode*>children;
    };
    
    TrieNode* getNode(string name){
        TrieNode* newNode=new TrieNode();

        newNode->name=name;
        newNode->subFolder="";

        return newNode;
    }

    void insert(TrieNode* root,vector<string>&path){
        for(string &folder:path){
            if(!root->children.count(folder)){
                root->children[folder]=getNode(folder);
            }
            root=root->children[folder];
        }
    }

    string populateNodes(TrieNode* root,unordered_map<string,int>&subFolderMap){
        vector<pair<string,string>>subFolderPaths;

        for(auto &[childName,child]:root->children){
            string subFolderResult=populateNodes(child,subFolderMap);

            subFolderPaths.push_back({childName,subFolderResult});
        }

        sort(begin(subFolderPaths),end(subFolderPaths));

        string completePath="";
        for(auto &[childName,childPath]:subFolderPaths){
            completePath+="("+childName+childPath+")";
        }

        root->subFolder=completePath;

        if(!completePath.empty()){
            subFolderMap[completePath]++;
        }

        return completePath;
    }

    void removeDuplicates(TrieNode* root,unordered_map<string,int>&subFolderMap){
        for(auto it=root->children.begin();it!=root->children.end();){
            string childName=it->first;
            TrieNode* child=it->second;

            if(!child->subFolder.empty() && subFolderMap[child->subFolder]>1){
                it=root->children.erase(it);
            } else{
                removeDuplicates(child,subFolderMap);
                it++;
            }
        }
    }

    void constructResult(TrieNode* root,vector<vector<string>>&ans,vector<string>&path){
        for(auto &[childName,child]:root->children){
            path.push_back(childName);
            ans.push_back(path);

            constructResult(child,ans,path);

            path.pop_back();
        }
    }
    public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>&paths){
        TrieNode* root=getNode("/");

        for(auto &path:paths){
            insert(root,path);
        }

        unordered_map<string,int>subFolderMap;
        populateNodes(root,subFolderMap);

        removeDuplicates(root,subFolderMap);

        vector<vector<string>>ans;
        vector<string>path;
        constructResult(root,ans,path);

        return ans;
    }
};
int main(){
    // Output: [["d"],["d","a"]]
    vector<vector<string>>paths={{"a"},{"c"},{"d"},{"a","b"},{"c","b"},{"d","a"}};
    // Output: [["c"],["c","b"],["a"],["a","b"]]
    vector<vector<string>>paths2={{"a"},{"c"},{"a","b"},{"c","b"},{"a","b","x"},{"a","b","x","y"},{"w"},{"w","y"}};
    // Output: [["c"],["c","d"],["a"],["a","b"]]
    vector<vector<string>>paths3={{"a","b"},{"c","d"},{"c"},{"a"}};

    Trie sol;
    vector<vector<string>>ans=sol.deleteDuplicateFolder(paths);

    for(auto &vec:ans){
        cout<<"[";
        for(string &s:vec){
            cout<<s<<" ";
        }
        cout<<"]";
    }
    return 0;
}