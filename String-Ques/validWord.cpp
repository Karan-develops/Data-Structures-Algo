// LC - 3136 - Easy - Valid Word
#include<iostream>
using namespace std;
bool isValid(string word){
    if(word.length()<3) return false;

    bool vowel=false,consonent=false;

    auto checkVowel=[](char ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    };

    for(char &ch:word){
        if(!isalnum(ch)) return false;

        if(isdigit(ch)) continue;

        if(checkVowel(tolower(ch))) vowel=true;
        else consonent=true;
    }
    return vowel && consonent;
}
int main(){
    // Output: true
    string word="234Adas";
    // Output: false
    string word2="b3";
    // Output: false
    string word3="a3$e";
    cout<<isValid(word)<<endl;
    cout<<isValid(word2)<<endl;
    cout<<isValid(word3);
    return 0;
}