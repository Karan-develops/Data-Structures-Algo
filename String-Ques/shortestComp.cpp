// LC - 748 - Easy - Shortest Completing Word
#include<iostream>
#include<vector>
using namespace std;
string shortestCompletingWord(string licensePlate,vector<string>&words){
    vector<int>plateChars(26,0);
    for(char &ch:licensePlate){
        if(isalpha(ch)){
            ch=tolower(ch);
            plateChars[ch-'a']++;
        }
    }
    string ans="";
    for(string &word:words){
        vector<int>currWord(26,0);
        for(char &ch:word){
            currWord[ch-'a']++;
        }
        bool valid=true;
        for(int i=0;i<26;i++){
            if(currWord[i]<plateChars[i]){
                valid=false;
                break;
            }
        }
        if(valid && (ans.empty() || ans.length()>word.length())){
            ans=word;
        }
    }
    return ans;
}
int main(){
    // Output: "steps"
    string licensePlate="1s3 PSt";
    vector<string>words={"step","steps","stripe","stepple"};
    // Output: "pest"
    string licensePlate2="1s3 456";
    vector<string>words2={"looks","pest","stew","show"};
    cout<<shortestCompletingWord(licensePlate,words)<<endl;
    cout<<shortestCompletingWord(licensePlate2,words2);
    return 0;
}