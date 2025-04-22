// LC - 3163 - Medium - String Compression III
#include<iostream>
using namespace std;
string compressedString(string word) {
    int n=word.length();
    string ans="";
    for(int i=0;i<n;i++){
        int count=1;
        while(i+1<n && count<9 && word[i]==word[i+1]){
            count++;
            i++;
        }
        ans+=to_string(count)+word[i];
    }
    return ans;
}
int main(){
    // Output: "1a1b1c1d1e"
    string word="abcde";
    // Output: "9a5a2b"
    string word2="aaaaaaaaaaaaaabb";
    cout<<compressedString(word)<<endl;
    cout<<compressedString(word2);
    return 0;
}