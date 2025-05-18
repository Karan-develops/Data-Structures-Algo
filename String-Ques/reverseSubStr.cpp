// LC - 3083 - Easy - Existence of a Substring in a String and Its Reverse
#include<iostream>
#include<algorithm>
using namespace std;
bool isSubstringPresent(string s) {
    string temp=s;
    reverse(begin(temp),end(temp));

    for(int i=0;i<s.length()-1;i++){
        string sub=s.substr(i,2);
        if(temp.find(sub)!=string::npos) return true;
    }
    return false;
}
int main(){
    // Output: true
    string s="leetcode";
    // Output: true
    string s2="abcba";
    // Output: false
    string s3="abcd";
    cout<<isSubstringPresent(s)<<endl;
    cout<<isSubstringPresent(s2)<<endl;
    cout<<isSubstringPresent(s3);
    return 0;
}