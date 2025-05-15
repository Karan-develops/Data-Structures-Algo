// LC - 520 - Easy - Detect Capital
#include<iostream>
using namespace std;
bool detectCapitalUse(string word){
    int capCount=0;
    for(char &ch:word){
        if(isupper(ch)) capCount++;
    }
    if(capCount==word.length() || capCount==0) return true;
    if(capCount==1 && isupper(word[0])) return true;
    return false;
}
int main(){
    // Output: true
    string word="USA";
    // Output: false
    string word2="FlaG";
    cout<<detectCapitalUse(word)<<endl;
    cout<<detectCapitalUse(word2);
    return 0;
}