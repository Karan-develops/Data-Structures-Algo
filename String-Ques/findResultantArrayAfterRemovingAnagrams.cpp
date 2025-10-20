// LC - 2273 - Easy - Find Resultant Array After Removing Anagrams
#include<iostream>
#include<vector>
using namespace std;
class String{
    bool checkAnagram(string s1,string s2){
        vector<int>v1(26,0);
        vector<int>v2(26,0);

        for(char &ch:s1) v1[ch-'a']++;
        for(char &ch:s2) v2[ch-'a']++;

        for(int i=0;i<26;i++){
            if(v1[i]!=v2[i]){
                return false;
            }
        }

        return true;
    }
    public:
    vector<string> removeAnagrams(vector<string>&words){
        int n=words.size();

        int i=0,j=1;
        
        while(j<n){
            if(checkAnagram(words[i],words[j])){
                words[j]="$";
                j++;
            } else{
                i=j;
                j++;
            }
        }

        vector<string>ans;
        for(string &s:words){
            if(s!="$"){
                ans.push_back(s);
            }
        }

        return ans;
    }
};
int main(){
    // Output: ["abba","cd"]
    vector<string>words={"abba","baba","bbaa","cd","cd"};
    // Output: ["a","b","c","d","e"]
    vector<string>words2={"a","b","c","d","e"};
    return 0;
}