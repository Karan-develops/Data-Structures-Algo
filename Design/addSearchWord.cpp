// LC - 211 - Medium - Design Add and Search Words Data Structure
#include<iostream>
using namespace std;
class Solution{
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
    // Initializing Root of Trie.
    TrieNode* root;
    Solution(){
        root=getNode();
    }
    void addWord(string word){
        TrieNode* crawler=root;
        for(char &ch:word){
            if(crawler->children[ch-'a']==NULL){
                crawler->children[ch-'a']=getNode();
            }
            crawler=crawler->children[ch-'a'];
        }
        crawler->endOfWord=true;
    }
    bool searchUtil(TrieNode* root,string word){
        TrieNode* crawler=root;
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            if(ch=='.'){
                for(int j=0;j<26;j++){
                    if(crawler->children[j]!=NULL && 
                        searchUtil(crawler->children[j],word.substr(i+1))){
                        return true;
                    }
                }
            } else if(crawler->children[ch-'a']==NULL){
                return false;
            }
            crawler=crawler->children[ch-'a'];
        }
        return (crawler->endOfWord && crawler!=NULL);
    }
    bool search(string word){
        return searchUtil(root,word);
    }
};