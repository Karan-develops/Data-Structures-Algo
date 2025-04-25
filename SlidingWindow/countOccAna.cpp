// GFG - Medium - Count Occurences of Anagrams
#include<iostream>
#include<vector>
using namespace std;
bool allZero(vector<int>&count){
    return count==vector<int>(26,0);
}
int search(string &pat,string &txt){
    int k=pat.length(),n=txt.length();
    vector<int>count(26,0);
    for(char &ch:pat) count[ch-'a']++;
    int i=0,j=0;
    int ans=0;
    while(j<n){
        count[txt[j]-'a']--;
        if(j-i+1==k){
            if(allZero(count)){
                ans++;
            }
            count[txt[i]-'a']++;
            i++;
        }
        j++;
    }
    return ans;
}
int main(){
    // Output: 3
    string txt="forxxorfxdofr",pat="for";
    // Output: 4
    string txt2="aabaabaa",pat2="aaba";
    cout<<search(pat,txt)<<endl;
    cout<<search(pat2,txt2);
    return 0;
}