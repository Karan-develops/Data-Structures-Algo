// LC - 2124 - Easy - Check if All A's Appears Before All B's
#include<iostream>
using namespace std;
bool checkString(string s) {
    bool flag=false;

    for(char &ch:s){
        if(flag && ch=='a') return false;
        if(ch=='b') flag=true;
    }
    return true;
}
int main(){
    // Output: true
    string s="aaabbb";
    // Output: false
    string s2="abab";
    // Output: true
    string s3="bbb";
    cout<<checkString(s)<<endl;
    cout<<checkString(s2)<<endl;
    cout<<checkString(s3);
    return 0;
}