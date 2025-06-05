// LC - 1061 - Medium - Lexicographically Smallest Equivalent String
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
class DFS{
    char dfs(unordered_map<char,vector<char>>&adj,vector<bool>&visited,char currChar){
        visited[currChar-'a']=true;
        char minChar=currChar;

        for(auto &ngbr:adj[currChar]){
            if(!visited[ngbr-'a']){
                minChar=min(minChar,dfs(adj,visited,ngbr));
            }
        }
        return minChar;
    }
    public:
    string smallestEquivalentString(string s1,string s2,string baseStr){
        unordered_map<char,vector<char>>adj;

        for(int i=0;i<s1.length();i++){
            int u=s1[i];
            int v=s2[i];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        string ans;
        for(int i=0;i<baseStr.length();i++){
            char ch=baseStr[i];

            vector<bool>visited(26,0);
            ans.push_back(dfs(adj,visited,ch));
        }
        return ans;
    }
};
class DSU{
    vector<int>parent;
    int find(int x){
        if(x==parent[x]){
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    void unite(int x,int y){
        int parent_x=find(x);
        int parent_y=find(y);
        
        if(parent_x!=parent_y){
            if(parent_x<parent_y){
                parent[parent_y]=parent_x;
            } else{
                parent[parent_x]=parent_y;
            }
        }
    }
    public:
    string smallestEquivalentString(string s1,string s2,string baseStr){
        parent.resize(26);

        for(int i=0;i<26;i++){
            parent[i]=i;
        }

        for(int i=0;i<s1.size();i++){
            unite(s1[i]-'a',s2[i]-'a');
        }

        string ans;
        for(char &ch:baseStr){
            ans+=(char)(find(ch-'a')+'a');
        }
        return ans;
    }
};
int main(){
    // Output: "makkek"
    string s1="parker",s2="morris",baseStr="parser";
    // Output: "hdld"
    string s3="hello",s4="world",baseStr2="hold";
    // Output: "aauaaaaada"
    string s5="leetcode",s6="programs",baseStr3="sourcecode";

    DSU sol;
    cout<<sol.smallestEquivalentString(s1,s2,baseStr)<<endl;
    cout<<sol.smallestEquivalentString(s3,s4,baseStr2)<<endl;
    cout<<sol.smallestEquivalentString(s5,s6,baseStr3);
    return 0;
}