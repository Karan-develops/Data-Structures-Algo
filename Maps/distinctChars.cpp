// LC - 2531 - Medium - Make Number of Distinct Characters Equal
// Good Question
#include<iostream>
#include<unordered_map>
using namespace std;
bool isItPossible(string word1, string word2) {
    unordered_map<char,int>mp1,mp2;
    
    for(char &ch:word1) mp1[ch]++;
    for(char &ch:word2) mp2[ch]++;

    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            char ch1=i+'a',ch2=j+'a';
            if(mp1.count(ch1) && mp2.count(ch2)){
                if(--mp1[ch1]==0) mp1.erase(ch1);
                if(--mp2[ch2]==0) mp2.erase(ch2);

                mp1[ch2]++;
                mp2[ch1]++;

                if(mp1.size()==mp2.size()) return true;

                if(--mp1[ch2] == 0) mp1.erase(ch2);
                if(--mp2[ch1] == 0) mp2.erase(ch1);

                mp1[ch1]++;
                mp2[ch2]++;
            }
        }
    }
    return false;
}
int main(){
    // Output: false
    string word1="ac",word2="b";
    // Output: true
    string word3="abcc",word4="aab";
    // Output: true
    string word5="abcde",word6="fghij";
    cout<<isItPossible(word1,word2)<<endl;
    cout<<isItPossible(word3,word4)<<endl;
    cout<<isItPossible(word5,word6);
    return 0;
}