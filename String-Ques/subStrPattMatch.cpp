// LC - 3407 - Easy - Substring Matching Pattern
// Acceptance Rate - 26%
#include<iostream>
using namespace std;
bool hasMatch(string s, string p) {
    int n=p.length();
    string temp="";
    string temp2="";
    int i=0;
    while(i<n){
        if(p[i]=='*') break;
        temp+=p[i];
        i++;
    }
    i++;
    while(i<n){
        temp2+=p[i++];
    }

    int x=s.find(temp);
    string abc=s.substr(x+temp.length());
    if(x==-1) return false;
    int y=abc.find(temp2);

    if(y==-1) return false;
    return true;
}
int main(){
    string s="leetcode",p="ee*e";
    // Output: true
    // Output: false
    string s2="car",p2="c*v";
    // Output: true
    string s3="luck",p3="u*";
    cout<<hasMatch(s,p)<<endl;
    cout<<hasMatch(s2,p2)<<endl;
    cout<<hasMatch(s3,p3);
    return 0;
}