// LC - 3121 - Medium - Count the Number of Special Characters II
#include<iostream>
#include<vector>
using namespace std;
int numberOfSpecialChars(string word) {
    int n=word.length();
    vector<pair<int,int>>low(26,{0,-1});
    vector<pair<int,int>>up(26,{0,n});

    for(int i=0;i<n;i++){
        char ch=word[i];
        if(islower(ch)){
            low[ch-'a'].first++;
            low[ch-'a'].second=i;
        } else{
            up[ch-'A'].first++;
            up[ch-'A'].second=min(up[ch-'A'].second,i);;
        }
    }
    int ans=0;
    for(int i=0;i<26;i++){
        if(low[i].first>0 && up[i].first>0){
            if(low[i].second<up[i].second) ans++;
        }
    }
    return ans;
}
int main(){
    // Output: 3
    string word="aaAbcBC";
    // Output: 0
    string word2="abc";
    // Output: 0
    string word3="AbBCab";
    cout<<numberOfSpecialChars(word)<<endl;
    cout<<numberOfSpecialChars(word2)<<endl;
    cout<<numberOfSpecialChars(word3);
    return 0;
}