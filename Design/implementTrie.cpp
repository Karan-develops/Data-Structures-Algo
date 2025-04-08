// LC - 208 - Medium - Implement Trie (Prefix Tree)
#include<iostream>
using namespace std;
class Trie{
    struct TrieNode{
        bool endOfWord;
        TrieNode* children[26];
    };
    TrieNode* getNode(){
        TrieNode* newNode=new TrieNode();
        newNode->endOfWord=false;
        for(int i=0;i<26;i++){
            newNode->children[i]=NULL;
        }
        return newNode;
    }
    // Intializing root of the Trie
    TrieNode* root;
    public:
    Trie(){
        root=getNode();
    }
    void insert(string word){
        TrieNode* crawler=root;
        for(char &ch:word){
            if(crawler->children[ch-'a']==NULL){
                crawler->children[ch-'a']=getNode();
            }
            crawler=crawler->children[ch-'a'];
        }
        crawler->endOfWord=true;
    }
    bool search(string word){
        TrieNode* crawler=root;
        for(char &ch:word){
            if(crawler->children[ch-'a']==NULL){
                return false;
            }
            crawler=crawler->children[ch-'a'];
        }
        return crawler->endOfWord;
    }
    bool startsWith(string prefix){
        TrieNode* crawler=root;
        for(char &ch:prefix){
            if(crawler->children[ch-'a']==NULL){
                return false;
            }
            crawler=crawler->children[ch-'a'];
        }
        return true;
    }
    ~Trie(){
        // Destructor to free memory
        for(int i=0;i<26;i++){
            if(root->children[i]!=NULL){
                delete root->children[i];
            }
        }
        delete root;
    }
};
int main(){
    Trie t;
    t.insert("apple");
    t.insert("apple");
    cout<<t.search("apple")<<endl;   // return True
    cout<<t.search("app")<<endl;     // return False
    cout<<t.startsWith("app")<<endl; // return True
    t.insert("app");
    cout<<t.search("app");     // return True
    return 0;
}