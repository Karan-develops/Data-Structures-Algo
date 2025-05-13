// LC - 3541 - Easy - Find Most Frequent Vowel and Consonant
#include<iostream>
#include<vector>
using namespace std;
int maxFreqSum(string s) {
    vector<int>vowels(26,0);
    vector<int>conso(26,0);

    auto isVowel=[&](char &ch){
        return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
    };

    for(char &ch:s){
        if(isVowel(ch)) vowels[ch-'a']++;
        else conso[ch-'a']++;
    }

    int vowelMax=0,consoMax=0;
    for(int i=0;i<26;i++){
        vowelMax=max(vowelMax,vowels[i]);
        consoMax=max(consoMax,conso[i]);
    }
    return vowelMax+consoMax;
}
int main(){
    // Output: 6
    string s="successes";
    // Output: 3
    string s2="aeiaeia";
    cout<<maxFreqSum(s)<<endl;
    cout<<maxFreqSum(s2);
    return 0;
}