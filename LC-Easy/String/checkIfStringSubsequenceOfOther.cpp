// GFG - Check if a String is Subsequence of Other
#include<iostream>
using namespace std;
bool isSubSeq(string &s1,string &s2){
    int m=s1.length();
    int n=s2.length();
    
    int i=0,j=0;
    
    while(i<m && j<n){
        if(s1[i]==s2[j]) i++;
        j++;
    }
    return i==m;
}
int main(){
    // Output: false
    string s1="AXY",s2="YADXCP";
    // Output: true
    string s3="gksrek",s4="geeksforgeeks";
    cout<<isSubSeq(s1,s2)<<endl;
    cout<<isSubSeq(s3,s4);
    return 0;
}