// LC - 140 - HARD - Word Break II
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class DP{
    int n;
    unordered_set<string>st;
    void solve(vector<string>&ans,string &s,string &currSentence,int i){
        if(i>=n){
            ans.push_back(currSentence);
            return;
        }

        for(int j=i;j<n;j++){
            string tempWord=s.substr(i,j-i+1);
            
            if(st.count(tempWord)){
                string tempSentence=currSentence;
                if(!currSentence.empty()){
                    currSentence+=" ";
                }
                // Take tempWord
                currSentence+=tempWord;
                // Explore
                solve(ans,s,currSentence,j+1);
                // Remove tempWord
                currSentence=tempSentence;
            }
        }
    }
    public:
    vector<string> wordBreak(string s,vector<string>&wordDict){
        n=s.length();
        st=unordered_set(begin(wordDict),end(wordDict));

        vector<string>ans;
        string currSentence;

        solve(ans,s,currSentence,0);
        return ans;
    }
};
int main(){
    // Output: ["cats and dog","cat sand dog"]
    string s="catsanddog";
    vector<string>wordDict={"cat","cats","and","sand","dog"};
    // Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
    string s2="pineapplepenapple";
    vector<string>wordDict2={"apple","pen","applepen","pine","pineapple"};
    // Output: []
    string s3="catsandog";
    vector<string>wordDict3={"cats","dog","sand","and","cat"};
    return 0;
}