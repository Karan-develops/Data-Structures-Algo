// LC - 844 - Easy - Backspace String Compare
#include<iostream>
#include<vector>
using namespace std;
bool backspaceCompare(string s,string t){
    string a="";
    string b="";
    for(char &ch:s){
        if(ch=='#' && a.length()) a.pop_back();
        else if(ch=='#' && a.length()==0) continue;
        else a.push_back(ch);
    }
    for(char &ch:t){
        if(ch=='#' && b.length()) b.pop_back();
        else if(ch=='#' && b.length()==0) continue;
        else b.push_back(ch);
    }
    return a==b;
}
int main(){
    // Output: true
    string s="ab#c",t="ad#c";
    // Output: true
    string s2="ab##",t2="c#d#";
    // Output: false
    string s3="a#c",t3="b";
    cout<<backspaceCompare(s,t)<<endl;
    cout<<backspaceCompare(s2,t2)<<endl;
    cout<<backspaceCompare(s3,t3);
    return 0;
}