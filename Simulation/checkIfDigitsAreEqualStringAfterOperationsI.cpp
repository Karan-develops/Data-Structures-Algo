// LC - 3461 - Easy - Check If Digits Are Equal in String After Operations I
#include<iostream>
using namespace std;
bool hasSameDigits(string s){
    int n=s.length();

    while(n>2){
        for(int i=0;i<n-1;i++){
            s[i]=(((s[i]-'0')+(s[i+1]-'0'))%10)+'0';
        }
        n--;
    }
    return s[0]==s[1];
}
int main(){
    // Output: true
    string s="3902";
    // Output: false
    string s2="34789";
    cout<<hasSameDigits(s)<<endl;
    cout<<hasSameDigits(s2);
    return 0;
}