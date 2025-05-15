// LC - 3120 - Easy - Count the Number of Special Characters I
#include<iostream>
#include<vector>
using namespace std;
int numberOfSpecialChars(string word) {
    vector<int>lower(26,0);
    vector<int>upper(26,0);

    for(char &ch:word){
        if(isupper(ch)) upper[ch-'A']++;
        else lower[ch-'a']++;
    }
    int ans=0;
    for(int i=0;i<26;i++){
        if(lower[i]>0 && upper[i]>0) ans++;
    }
    return ans;
}
int main(){
    // Output: 3
    string word="aaAbcBC";
    // Output: 0
    string word2="abc";
    // Output: 1
    string word3="abBCab";
    cout<<numberOfSpecialChars(word)<<endl;
    cout<<numberOfSpecialChars(word2)<<endl;
    cout<<numberOfSpecialChars(word3);
    return 0;
}