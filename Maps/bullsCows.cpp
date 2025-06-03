// LC - 299 - Medium - Bulls and Cows
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
string getHint(string secret,string guess){
    int bulls=0,cows=0;

    unordered_map<char,int>mp;

    for(char &ch:secret) mp[ch]++;

    for(int i=0;i<secret.length();i++){
        if(secret[i]==guess[i]){
            bulls++;
            mp[secret[i]]--;
        }
    }

    for(int i=0;i<guess.length();i++){
        if(mp[guess[i]]>0 && guess[i]!=secret[i]){
            cows++;
            mp[guess[i]]--;
        }
    }
    string ans=to_string(bulls)+"A"+to_string(cows)+"B";
    return ans;
}
int main(){
    // Output: "1A3B"
    string secret="1807",guess="7810";
    // Output: "1A1B"
    string secret2="1123",guess2="0111";
    cout<<getHint(secret,guess)<<endl;
    cout<<getHint(secret2,guess2);
    return 0;
}