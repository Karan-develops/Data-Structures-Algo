// LC - 3330 - Easy - Find the Original Typed String I
#include<iostream>
using namespace std;
int possibleStringCount(string word){
    int ans=0;

    for(int i=1;i<word.length();i++){
        if(word[i-1]==word[i]) ans++;
    }
    return ans+1;
}
int main(){
    // Output: 5
    string word="abbcccc";
    // Output: 1
    string word2="abcd";
    // Output: 4
    string word3="aaaa";
    cout<<possibleStringCount(word)<<endl;
    cout<<possibleStringCount(word2)<<endl;
    cout<<possibleStringCount(word3);
    return 0;
}