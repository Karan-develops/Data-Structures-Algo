// LC - 151 - Medium - Reverse Words in a String
#include<iostream>
#include<sstream>
using namespace std;
string reverseWords(string s){
    stringstream ss(s);
    string token;
    string ans;

    while(ss>>token){
        ans=token+" "+ans;
    }
    return ans.substr(0,ans.length()-1);
}
int main(){
    // Output: "blue is sky the"
    string s="the sky is blue";
    // Output: "world hello"
    string s2="  hello world  ";
    // Output: "example good a"
    string s3="a good   example";
    cout<<reverseWords(s)<<endl;
    cout<<reverseWords(s2)<<endl;
    cout<<reverseWords(s3);
    return 0;
}