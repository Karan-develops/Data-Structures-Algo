// LC - 1839 - Medium - Longest Substring Of All Vowels in Order
#include<iostream>
#include<vector>
using namespace std;
int longestBeautifulSubstring(string word){
    int n=word.length();
    int ans=0;

    int i=0;

    while(i<n){
        // Always Start with 'a'
        if(word[i]!='a'){
            i++;
            continue;
        }

        int j=i;
        int vowelCount=1;

        while(j<n-1 && word[j]<=word[j+1]){
            if(word[j]<word[j+1]) vowelCount++;
            j++;
        }

        if(vowelCount==5) ans=max(ans,j-i+1);

        i=j+1;
    }
    return ans;
}
int main(){
    // Output: 13
    string word="aeiaaioaaaaeiiiiouuuooaauuaeiu";
    // Output: 5
    string word2="aeeeiiiioooauuuaeiou";
    // Output: 0
    string word3="a";
    cout<<longestBeautifulSubstring(word)<<endl;
    cout<<longestBeautifulSubstring(word2)<<endl;
    cout<<longestBeautifulSubstring(word3);
    return 0;
}