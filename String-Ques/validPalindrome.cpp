// LC - 125 - Easy - Valid Palindrome
#include<iostream>
using namespace std;
bool isPalindrome(string s){
    int l=0,r=s.length()-1;

    while(l<=r){
        // isalnum returns true if the char is a-z, A-Z, 0-9
        while(l<r && !isalnum(s[l])) l++;
        while(l<r && !isalnum(s[r])) r--;

        if(tolower(s[l])!=tolower(s[r])) return false;

        l++,r--;
    }
    return true;
}
int main(){
    // Output: true
    string s="A man, a plan, a canal: Panama";
    // Output: false
    string s2="race a car";
    // Output: true
    string s3=" ";
    cout<<isPalindrome(s)<<endl;
    cout<<isPalindrome(s2)<<endl;
    cout<<isPalindrome(s3);
    return 0;
}