// LC - 2287 - Easy - Rearrange Characters to Make Target String
#include<iostream>
#include<vector>
using namespace std;
int rearrangeCharacters(string s, string target) {
    vector<int>v(26,0);
    for(char &ch:s) v[ch-'a']++;

    int ans=0;
    while(true){
        for(char &ch:target){
            if(v[ch-'a']==0) return ans;
            v[ch-'a']--;
        }
        ans++;
    }
    return ans;
}
int main(){
    // Output: 2
    string s="ilovecodingonleetcode",target="code";
    // Output: 1
    string s2="abcba",target2="abc";
    // Output: 1
    string s3="abbaccaddaeea",target3="aaaaa";
    cout<<rearrangeCharacters(s,target)<<endl;
    cout<<rearrangeCharacters(s2,target2)<<endl;
    cout<<rearrangeCharacters(s3,target3);
    return 0;
}