#include<iostream>
#include<unordered_map>
using namespace std;
class TrieNode{
    public:
    unordered_map<char,TrieNode*>children;
    bool isEndOfWord;
    TrieNode(){
        this->isEndOfWord=false;
    }
};
class Trie{
    private:
    TrieNode* root;
    public:
    Trie(){
        root=new TrieNode();
    }
    void insert(const string& word){
        
    }
    void displayChildren(){
        
    }
};
int main(){
    Trie trie;
     // Insert words into the Trie
    trie.insert("cat");
    trie.insert("can");
    trie.insert("dog");

    // Test: Display children of the root
    trie.displayChildren();
}