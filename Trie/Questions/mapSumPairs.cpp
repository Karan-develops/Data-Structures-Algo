// LC - 677 - Medium - Map Sum Pairs
// Also Solved Using Map
#include<iostream>
using namespace std;
class Trie{
    struct TrieNode{
        char ch;
        int val=0;
        TrieNode* children[26];
    };
    TrieNode* getNode(char ch){
        TrieNode* newNode=new TrieNode();

        newNode->ch=ch;
        for(int i=0;i<26;i++){
            newNode->children[i]=NULL;
        }
        return newNode;
    }
    void insertNode(string &key,int val){
        TrieNode* crawler=root;

        for(char &ch:key){
            if(crawler->children[ch-'a']==NULL){
                crawler->children[ch-'a']=getNode(ch);
            }
            crawler=crawler->children[ch-'a'];
        }
        crawler->val=val;
    }
    int findSum(TrieNode* crawler){
        if(!crawler) return 0;

        int sum=crawler->val;
        for(int i=0;i<26;i++){
            sum+=findSum(crawler->children[i]);
        }
        return sum;
    }
    public:
    // Initializing Root
    TrieNode* root=NULL;
    Trie() {
        root=getNode('/');
    }
    
    void insert(string key,int val){
        insertNode(key,val);
    }
    
    int sum(string prefix){
        TrieNode* crawler=root;

        for(char &ch:prefix){
            if(crawler->children[ch-'a']==NULL){
                return 0;
            }
            crawler=crawler->children[ch-'a'];
        }
        return crawler==NULL?0:findSum(crawler);
    }
};
/*
Example 1:
Input
["MapSum", "insert", "sum", "insert", "sum"]
[[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
Output
[null, null, 3, null, 5]
*/