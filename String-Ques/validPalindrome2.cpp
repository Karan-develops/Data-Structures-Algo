// LC - 680 - Easy - Valid Palindrome II
#include<iostream>
using namespace std;
class Solution{
    bool checkPalindrome(string s,int i,int j){
        while(i<=j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    public:
    bool validPalindrome(string s){
        int i=0;
        int j=s.length()-1;

        while(i<=j){
            if(s[i]!=s[j]){
                return checkPalindrome(s,i+1,j) || checkPalindrome(s,i,j-1);
            }
            else i++,j--;
        }
        return true;
    }
};
int main(){
    // Output: true
    string s="aba";
    // Output: true
    string s2="abca";
    // Output: false
    string s3="abc";
    
    Solution sol;
    cout<<sol.validPalindrome(s)<<endl;
    cout<<sol.validPalindrome(s2)<<endl;
    cout<<sol.validPalindrome(s3);
    return 0;
}