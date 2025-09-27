// LC - 1268 - Medium - Search Suggestions System
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Trie{
    struct TrieNode{
        char ch;
        bool endOfWord;
        TrieNode* children[26]={NULL};
    };
    TrieNode* getNode(char ch){
        TrieNode* newNode=new TrieNode();

        newNode->ch=ch;
        newNode->endOfWord=false;
        return newNode;
    }
    void insert(TrieNode* root,const string &word){
        TrieNode* crawler=root;

        for(const char &ch:word){
            if(crawler->children[ch-'a']==NULL){
                crawler->children[ch-'a']=getNode(ch);
            }
            crawler=crawler->children[ch-'a'];
        }
        crawler->endOfWord=true;
    }
    void getWord(TrieNode* crawler,string &prefix,vector<string>&ans){
        if(ans.size()==3) return;

        if(crawler->endOfWord==true){
            ans.push_back(prefix);
        }

        for(char ch='a';ch<='z';ch++){
            TrieNode* nextNode=crawler->children[ch-'a'];
            
            if(nextNode){
                prefix.push_back(ch);
                getWord(nextNode,prefix,ans);
                prefix.pop_back();
            }
        }
    }
    vector<string> search(TrieNode* root,string &prefix){
        TrieNode* crawler=root;
        vector<string>ans;

        for(const char &ch:prefix){
            if(crawler->children[ch-'a']==NULL){
                return ans;
            }
            crawler=crawler->children[ch-'a'];
        }

        getWord(crawler,prefix,ans);
        
        return ans;
    }
    public:
    vector<vector<string>> suggestedProducts(vector<string>&products,string searchWord){
        TrieNode* root=getNode('.');

        for(const string &product:products){
            insert(root,product);
        }

        vector<vector<string>>ans;
        string prefix;

        for(char &ch:searchWord){
            prefix.push_back(ch);
            ans.push_back(search(root,prefix));
        }

        return ans;
    }
};
int main(){
    // Output: [["mobile","moneypot","monitor"],["mobile","moneypot","monitor"],["mouse","mousepad"],["mouse","mousepad"],["mouse","mousepad"]]
    vector<string>products={"mobile","mouse","moneypot","monitor","mousepad"};
    string searchWord="mouse";
    // Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
    vector<string>products2={"havana"};
    string searchWord2="havana";
    return 0;
}