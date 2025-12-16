// GFG - Medium - Strings Rotations of Each Other
#include<iostream>
using namespace std;
bool areRotations(string &s1, string &s2) {
    if((s1+s1).find(s2)!=string::npos) return true;

    return false;
}
int main(){
    // Output: true
    string s1="abcd",s2="cdab";
    // Output: true
    string s3="aab",s4="aba";
    // Output: false
    string s5="abcd",s6="acbd";
    cout<<areRotations(s1,s2)<<endl;
    cout<<areRotations(s3,s4)<<endl;
    cout<<areRotations(s5,s6);
    return 0;
}