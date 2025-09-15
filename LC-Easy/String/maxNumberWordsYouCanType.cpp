// LC - 1935 - Easy - Maximum Number of Words You Can Type
#include<iostream>
#include<unordered_set>
#include<sstream>
using namespace std;
int canBeTypedWords(string text,string brokenLetters){
    int ans=0;

    unordered_set<char>st(begin(brokenLetters),end(brokenLetters));

    stringstream ss(text);
    string token;

    while(getline(ss,token,' ')){
        bool flag=true;
        for(char &ch:token){
            if(st.count(ch)){
                flag=false;
                break;
            }
        }
        if(flag) ans++;
    }

    return ans;
}
int main(){
    // Output: 1
    string text="hello world",brokenLetters="ad";
    // Output: 1
    string text2="leet code",brokenLetters2="lt";
    // Output: 0
    string text3="leet code",brokenLetters3="e";
    cout<<canBeTypedWords(text,brokenLetters)<<endl;
    cout<<canBeTypedWords(text2,brokenLetters2)<<endl;
    cout<<canBeTypedWords(text3,brokenLetters3);
    return 0;
}