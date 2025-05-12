// LC - 2114 - Easy - Maximum Number of Words Found in Sentences
#include<iostream>
#include<vector>
#include<sstream>
using namespace std;
int mostWordsFound(vector<string>& sentences) {
    int ans=0;
    for(string &s:sentences){
        int count=0;
        stringstream ss(s);
        string token;
        while(getline(ss,token,' ')){
            count++;
        }
        ans=max(ans,count);
    }
    return ans;
}
int main(){
    // Output: 6
    vector<string>sentences={"alice and bob love leetcode", "i think so too", "this is great thanks very much"};
    // Output: 3
    vector<string>sentences2={"please wait", "continue to fight", "continue to win"};
    cout<<mostWordsFound(sentences)<<endl;
    cout<<mostWordsFound(sentences2);
    return 0;
}