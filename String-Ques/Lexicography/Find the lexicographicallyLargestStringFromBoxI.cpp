// LC - 3403 - Medium - Find the Lexicographically Largest String From the Box I
#include<iostream>
using namespace std;
class Lexico{
    int n;
    void checkLex(string &word,char &lex,int i,int &idx){
        int x=idx,y=i;
        while(x<n && y<n){
            if(word[x+1]!=word[y+1]){
                idx=(word[x+1]<word[y+1])?i:idx;
                break;
            }
            x++,y++;
        }
    }
    public:
    string answerString(string word, int numFriends) {
        n=word.length();

        if(numFriends==1) return word;

        char lex=word[0];
        int idx=0;
        
        for(int i=0;i<n;i++){
            if(lex==word[i]){
                checkLex(word,lex,i,idx);
            }
            else if(lex<word[i]){
                lex=word[i];
                idx=i;
            }
        }
        int x=n-numFriends+1;
        return word.substr(idx,x);
    }
    string answerString2(string word,int numFriends){
        int n=word.length();
        if(numFriends==1) return word;

        string ans;

        int longestPossible=n-(numFriends-1);

        for(int i=0;i<n;i++){
            int canTakeLength=min(longestPossible,n-i);

            ans=max(ans,word.substr(i,canTakeLength));
        }
        return ans;
    }
};
int main(){
    // Output: "dbc"
    string word="dbca";
    int numFriends=2;
    // Output: "g"
    string word2="gggg";
    int numFriends2=4;

    Lexico sol;
    cout<<sol.answerString(word,numFriends)<<endl;
    cout<<sol.answerString(word2,numFriends2);
    return 0;
}