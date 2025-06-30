// LC - 58 - Easy - Length of Last Word
#include<iostream>
using namespace std;
int lengthOfLastWord(string s){
    int n=s.length();
    int ans=0;

    int i=n-1;
    while(i>=0 && s[i]==' ') i--;

    while(i>=0 && s[i]!=' '){
        ans++;
        i--;
    }
    return ans;
}
int main(){
    // Output: 5
    string s="Hello World";
    // Output: 4
    string s2="   fly me   to   the moon  ";
    // Output: 6
    string s3="luffy is still joyboy";
    cout<<lengthOfLastWord(s)<<endl;
    cout<<lengthOfLastWord(s2)<<endl;
    cout<<lengthOfLastWord(s3);
    return 0;
}