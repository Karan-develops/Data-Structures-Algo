#include<iostream>
using namespace std;
bool checkPalindrome(string& str,int i,int n){
    if(i>n){
        return true;
    }
    if(str[i]!=str[n]) return false;
    return checkPalindrome(str,i+1,n-1);
}
int main(){
    string str="epajfxzfnvte";
    int n=str.length()-1;
    if(checkPalindrome(str,0,n)){
        cout<<"Yes";
    } else{
        cout<<"No";
    }
    return 0;
}