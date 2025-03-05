#include<iostream>
#include<queue>
using namespace std;
string nonRepeatingChars(string &s){
    int l=s.length();
    int mapping[26]={0};
    string ans="";
    queue<char>q;
    for(int i=0;i<l;i++){
        char ch=s[i];
        // increment frequency
        mapping[ch-'a']++;
        // push in queue
        q.push(ch);
        while(!q.empty()){
            // if repeating then pop from queue
            if(mapping[q.front()-'a']>1) q.pop();
            else{
                ans.push_back(q.front());
                break;
            }
        }
        if(q.empty()) ans.push_back('#');
    }
    return ans;
}
int main(){
    string s="aaabcd";
    string ans=nonRepeatingChars(s);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}