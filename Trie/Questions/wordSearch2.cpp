// LC - 212 - HARD - Word Search II
#include<iostream>
#include<vector>
using namespace std;
class Solution{
    int m,n;
    vector<string>ans;
    vector<vector<int>>directions={{0,1},{1,0},{0,-1},{-1,0}};
    struct TrieNode{
        bool endOfWord;
        string word;
        TrieNode* children[26];
    };
    TrieNode* root;
    TrieNode* getNode(){
        TrieNode* newNode=new TrieNode();
        newNode->endOfWord=false;
        newNode->word="";
        for(int i=0;i<26;i++){
            newNode->children[i]=NULL;
        }
        return newNode;
    }
    void insert(TrieNode* root,string word){
        TrieNode* crawler=root;
        for(char &ch:word){
            if(crawler->children[ch-'a']==NULL){
                crawler->children[ch-'a']=getNode();
            }
            crawler=crawler->children[ch-'a'];
        }
        crawler->endOfWord=true;
        crawler->word=word;
    }
    void findWordsInTrie(vector<vector<char>>&board,TrieNode* root,int i,int j){
        if(i<0 || i>=m || j<0 || j>=n || board[i][j]=='$'
            || root->children[board[i][j]-'a']==NULL){
            return;
        }

        root=root->children[board[i][j]-'a'];
        if(root->endOfWord==true){
            ans.push_back(root->word);
            root->endOfWord=false;
        }

        char temp=board[i][j];
        board[i][j]='$';
        
        for(auto &dir:directions){
            int i_=i+dir[0];
            int j_=j+dir[1];
            findWordsInTrie(board,root,i_,j_);
        }
        board[i][j]=temp;
    }
    public:
    vector<string> findWords(vector<vector<char>>&board,vector<string>&words){
        m=board.size(),n=board[0].size();
        ans.clear();
        root=getNode();

        for(string &word:words){
            insert(root,word);
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                char ch=board[i][j];
                if(root->children[ch-'a']!=NULL){
                    findWordsInTrie(board,root,i,j);
                }
            }
        }
        return ans;
    }
    ~Solution(){
        clearTrie(root);
    }
    private:
    void clearTrie(TrieNode* node){
        if(!node) return;
        for(int i=0;i<26;i++){
            if(node->children[i]){
                clearTrie(node->children[i]);
            }
        }
        delete node;
    }
};
int main(){
    // Output: ['eat','oath']
    vector<vector<char>>board={{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    vector<string>words={"oath","pea","eat","rain"};
    // Output: []
    vector<vector<char>>board2={{'a','b'},{'c','d'}};
    vector<string>words2={"abcb"};
    Solution sol;
    vector<string>ans=sol.findWords(board,words);
    for(auto &s:ans) cout<<s<<" ";
    return 0;
}