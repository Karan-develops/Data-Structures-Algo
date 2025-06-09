// LC - 1544 - Easy - Make The String Great
#include<iostream>
using namespace std;
bool checkGood(string &s,char ch1,char ch2){
    if(tolower(ch1)==tolower(ch2)){
        if(islower(ch1) && isupper(ch2) || 
            islower(ch2) && isupper(ch1)
        ) return true;
    }
    return false;
}
string makeGood(string s){
    int n=s.length();
    string ans="";

    for(int i=0;i<n;i++){
        if(ans.empty()) ans+=s[i];
        else{
            if(checkGood(s,s[i],ans.back())) ans.pop_back();
            else ans.push_back(s[i]);
        }
    }
    return ans;
}
int main(){
    // Output: "leetcode"
    string s="leEeetcode";
    // Output: ""
    string s2="abBAcC";
    // Output: "s"
    string s3="s";

    cout<<makeGood(s)<<endl;
    cout<<makeGood(s2)<<endl;
    cout<<makeGood(s3);
    return 0;
}