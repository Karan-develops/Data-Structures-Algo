// LC - 2047 - Easy - Number of Valid Words in a Sentence
// Acceptance Rate - 29%
#include<iostream>
#include<sstream>
using namespace std;
class Solution {
public:
    bool isValid(string &s){
        int n=s.length();
        int hyphen=0;
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(isdigit(ch) || (ch=='!' && i!=n-1) ) return false;
            if(isalpha(ch)) continue;

            if(ch=='-'){
                if(++hyphen>1) return false;
                if(i==n-1 || i==0 || !isalpha(s[i-1]) || !isalpha(s[i+1])) return false;
            } else if(i!=n-1) return false;
        }
        return true;
    }
    int countValidWords(string sentence) {
        int ans=0;
        stringstream ss(sentence);
        string token;

        while(getline(ss,token,' ')){
            if(token.empty()) continue;
            ans+=isValid(token);
        }
        return ans;
    }
};
int main(){
    // Output: 3
    string sentence="cat and  dog";
    // Output: 0
    string sentence2="!this  1-s b8d!";
    // Output: 5
    string sentence3="alice and  bob are playing stone-game10";
    Solution sol;
    cout<<sol.countValidWords(sentence)<<endl;
    cout<<sol.countValidWords(sentence2)<<endl;
    cout<<sol.countValidWords(sentence3);
    return 0;
}