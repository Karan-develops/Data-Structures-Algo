// LC - 557 - Easy - Reverse Words in a String III
#include<iostream>
#include<sstream>
#include<algorithm>
using namespace std;
string reverseWords(string s) {
    stringstream ss(s);
    string token;
    string ans="";

    while(getline(ss,token,' ')){
        reverse(begin(token),end(token));
        ans+=token;
        ans+=" ";
    }
    ans=ans.substr(0,ans.length()-1);
    return ans;
}
int main(){
    // Output: "s'teL ekat edoCteeL tsetnoc"
    string s="Let's take LeetCode contest";
    // Output: "rM gniD"
    string s2="Mr Ding";
    cout<<reverseWords(s)<<endl;
    cout<<reverseWords(s2);
    return 0;
}