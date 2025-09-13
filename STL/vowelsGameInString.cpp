// LC - 3227 - Medium - Vowels Game in a String
#include<iostream>
#include<algorithm>
using namespace std;
bool doesAliceWin(string s){
    auto lambda=[](char ch){
        return string("aeiou").find(ch)!=string::npos;
    };

    return any_of(begin(s),end(s),lambda);
}
int main(){
    // Output: true
    string s="leetcoder";
    // Output: false
    string s2="bbcd";
    cout<<doesAliceWin(s)<<endl;
    cout<<doesAliceWin(s2);
    return 0;
}