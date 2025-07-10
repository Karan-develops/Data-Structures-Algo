// GFG - Find the longest string
#include<iostream>
#include<vector>
using namespace std;
class Trie{
    struct TrieNode{
        bool endOfWord;
        TrieNode* children[26];
    };
    TrieNode* getNode(){
        TrieNode* newNode=new TrieNode();
        newNode->endOfWord=false;

        for(int i=0;i<25;i++){
            newNode->children[i]=NULL;
        }
        return newNode;
    }
    TrieNode* root=new TrieNode();

    void insert(string &word){
        TrieNode* crawler=root;

        for(char &ch:word){
            if(crawler->children[ch-'a']==NULL){
                crawler->children[ch-'a']=getNode();
            }
            crawler=crawler->children[ch-'a'];
        }
        crawler->endOfWord=true;
    }
    bool searchPrefix(string &word){
        TrieNode* crawler=root;

        for(char &ch:word){
            crawler=crawler->children[ch-'a'];
            if(crawler==NULL || crawler->endOfWord==false){
                return false;
            }
        }
        return true;
    }
    public:
    string longestString(vector<string>&words){
        for(string &s:words){
            insert(s);
        }

        string ans="";
        for(string &s:words){
            if(searchPrefix(s)){
                if((s.length()>ans.length()) || (s.length()==ans.length() && s<ans)){
                    ans=s;
                }
            }
        }
        return ans;
    }
};
int main(){
    // Output: pros
    vector<string>words={"p","pr","pro","probl","problem","pros","process","processor"};
    // Output: abc
    vector<string>words2={"ab","a","abc","abd"};

    Trie sol;
    cout<<sol.longestString(words)<<endl;
    cout<<sol.longestString(words2);
    return 0;
}