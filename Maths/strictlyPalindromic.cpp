// LC - 2396 - Medium - Strictly Palindromic Number
#include<iostream>
using namespace std;
bool isStrictlyPalindromic(int n){
    return false; // Always
}
int main(){
    // Output: false
    int n=9;
    // Output: false
    int n2=4;
    cout<<isStrictlyPalindromic(n)<<endl;
    cout<<isStrictlyPalindromic(n2);
    return 0;
}