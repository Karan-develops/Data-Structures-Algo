// LC - 1844 - Easy - Replace All Digits with Characters
#include<iostream>
using namespace std;
string replaceDigits(string s){
    int n=s.length();

    for(int i=1;i<n;i+=2){
        s[i]=(char)s[i-1]+s[i]-'0';
    }
    return s;
}
int main(){
    // Output: "abcdef"
    string s="a1c1e1";
    // Output: "abbdcfdhe"
    string s2="a1b2c3d4e";
    cout<<replaceDigits(s)<<endl;
    cout<<replaceDigits(s2);
    return 0;
}