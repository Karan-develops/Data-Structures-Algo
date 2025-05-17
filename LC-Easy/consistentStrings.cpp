// LC - 1684 - Easy - Count the Number of Consistent Strings
#include<iostream>
#include<vector>
using namespace std;
int countConsistentStrings(string allowed, vector<string>& words) {
    vector<int>v(26,0);
    for(char &ch:allowed) v[ch-'a']++;

    int ans=0;
    for(string &s:words){
        bool flag=true;
        for(char &ch:s){
            if(v[ch-'a']==0){
                flag=false;
                break;
            }
        }
        if(flag) ans++;
    }
    return ans;
}
int main(){
    // Output: 2
    string allowed="ab";
    vector<string>words={"ad","bd","aaab","baa","badab"};
    // Output: 7
    string allowed2="abc";
    vector<string>words2={"a","b","c","ab","ac","bc","abc"};
    // Output: 4
    string allowed3="cad";
    vector<string>words3={"cc","acd","b","ba","bac","bad","ac","d"};
    cout<<countConsistentStrings(allowed,words)<<endl;
    cout<<countConsistentStrings(allowed2,words2)<<endl;
    cout<<countConsistentStrings(allowed3,words3);
    return 0;
}