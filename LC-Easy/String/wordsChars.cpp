// LC - 2942 - Easy - Find Words Containing Character
#include<iostream>
#include<vector>
using namespace std;
vector<int> findWordsContaining(vector<string>& words, char x) {
    vector<int>ans;
    for(int i=0;i<words.size();i++){
        for(char &ch:words[i]){
            if(ch==x){
                ans.push_back(i);
                break;
            }
        }
    }
    return ans;
}
int main(){
    // Output: [0,1]
    vector<string>words={"leet","code"};
    char x='e';
    // Output: [0,2]
    vector<string>words2={"abc","bcd","aaaa","cbc"};
    char x2='a';
    // Output: []
    vector<string>words3={"abc","bcd","aaaa","cbc"};
    char x3='z';
    return 0;
}