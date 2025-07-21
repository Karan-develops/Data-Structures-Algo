// LC - 1957 - Easy - Delete Characters to Make Fancy String
#include<iostream>
using namespace std;
string makeFancyString(string s){
    int n=s.length();
    string ans="";
    int count=1;

    ans.push_back(s[0]);

    for(int i=1;i<n;i++){
        if(s[i]==ans.back()){
            count++;
            if(count<3){
                ans.push_back(s[i]);
            }
        } else{
            ans.push_back(s[i]);
            count=1;
        }
    }
    return ans;
}
int main(){
    // Output: "leetcode"
    string s="leeetcode";
    // Output: "aabaa"
    string s2="aaabaaaa";
    // Output: "aab"
    string s3="aab";
    cout<<makeFancyString(s)<<endl;
    cout<<makeFancyString(s2)<<endl;
    cout<<makeFancyString(s3);
    return 0;
}