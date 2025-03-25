// LC - 1328 - Medium - Break a Palindrome
#include<iostream>
using namespace std;
string breakPalindrome(string palindrome){
    int n=palindrome.length();
    if(n==1) return "";

    for(int i=0;i<n/2;i++){
        char ch=palindrome[i];
        if(ch!='a'){
            palindrome[i]='a';
            return palindrome;
        }
    }
    palindrome[n-1]='b';
    return palindrome;
}
int main(){
    // Output: "aaccba"
    string palindrome = "abccba";
    // Output: ""
    string palindrome2="a";
    // Output: "aab"
    string palindrome3="aaa";
    cout<<breakPalindrome(palindrome)<<endl;
    cout<<breakPalindrome(palindrome2)<<endl;
    cout<<breakPalindrome(palindrome3);
    return 0;
}