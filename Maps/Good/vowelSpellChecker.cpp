// LC - 966 - Medium - Vowel Spellchecker
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Map{
    unordered_set<string>exactWords;
    unordered_map<string,string>caseMp;
    unordered_map<string,string>vowelMp;
    string toLower(const string &s){
        string ans=s;

        for(char &ch:ans){
            ch=tolower(ch);
        }
        return ans;
    }
    string maskVowels(const string &s){
        string ans=s;

        for(char &ch:ans){
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
                ch='*';
            }
        }
        return ans;
    }
    string checkForMatch(const string &query){
        if(exactWords.count(query)){
            return query;
        }

        string lowerQuery=toLower(query);
        if(caseMp.count(lowerQuery)){
            return caseMp[lowerQuery];
        }

        string maskedQuery=maskVowels(lowerQuery);
        if(vowelMp.count(maskedQuery)){
            return vowelMp[maskedQuery];
        }

        return "";
    }
    public:
    vector<string> spellchecker(vector<string>&wordlist,vector<string>&queries){
        exactWords.clear();
        caseMp.clear();
        vowelMp.clear();

        for(string &s:wordlist){
            exactWords.insert(s);

            string lowerWord=toLower(s);
            if(caseMp.find(lowerWord)==caseMp.end()){
                caseMp[lowerWord]=s;
            }

            string maskedWord=maskVowels(lowerWord);
            if(vowelMp.find(maskedWord)==vowelMp.end()){
                vowelMp[maskedWord]=s;
            }
        }

        vector<string>ans;
        for(string &query:queries){
            ans.push_back(checkForMatch(query));
        }

        return ans;
    }
};
int main(){
    // Output: ["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]
    vector<string>wordlist={"KiTe","kite","hare","Hare"},queries={"kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"};
    // Output: ["yellow"]
    vector<string>wordlist2={"yellow"},queries2={"YellOw"};
    return 0;
}