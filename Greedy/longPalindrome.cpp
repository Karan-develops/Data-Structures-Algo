// LC - 2131 - Medium - Longest Palindrome by Concatenating Two Letter Words
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int longestPalindrome(vector<string>&words){
    int ans=0;
    unordered_map<string,int>mp;

    for(string &word:words){
        string reversedWord=word;
        swap(reversedWord[0],reversedWord[1]);

        if(mp[reversedWord]>0){
            ans+=4;
            mp[reversedWord]--;
        } else{
            mp[word]++;
        }
    }

    for(auto &it:mp){
        string word=it.first;
        int count=it.second;

        if(word[0]==word[1] && count>0){
            ans+=2;
            break;
        }
    }
    return ans;
}
int main(){
    // Output: 6
    vector<string>words={"lc","cl","gg"};
    // Output: 8
    vector<string>words2={"ab","ty","yt","lc","cl","ab"};
    // Output: 2
    vector<string>words3={"cc","ll","xx"};
    cout<<longestPalindrome(words)<<endl;
    cout<<longestPalindrome(words2)<<endl;
    cout<<longestPalindrome(words3);
}