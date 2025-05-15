// LC - 2309 - Easy - Greatest English Letter in Upper and Lower Case
#include<iostream>
#include<vector>
using namespace std;
string greatestLetter(string s) {
    vector<bool>low(26,false);
    vector<bool>up(26,false);

    for(char &ch:s){
        if(islower(ch)) low[ch-'a']=true;
        else up[ch-'A']=true;
    }
    string ans="";
    for(int i=0;i<26;i++){
        if(low[i] && up[i]) ans=i+'A';
    }
    return ans;
}
int main(){
    // Output: "E"
    string s="lEeTcOdE";
    // Output: "R"
    string s2="arRAzFif";
    // Output: ""
    string s3="AbCdEfGhIjK";
    cout<<greatestLetter(s)<<endl;
    cout<<greatestLetter(s2)<<endl;
    cout<<greatestLetter(s3);
    return 0;
}