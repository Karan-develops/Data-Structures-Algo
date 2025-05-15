// LC - 2900 - Easy - Longest Unequal Adjacent Groups Subsequence I
#include<iostream>
#include<vector>
using namespace std;
vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
    int n=groups.size();
    vector<string>ans;
    ans.push_back(words[0]);
    int i=0,j=0;
    while(j<n){
        if(groups[i]==groups[j]) j++;
        else{
            ans.push_back(words[j]);
            i=j;
        }
    }
    return ans;
}
int main(){
    // Output: ["e","b"]
    vector<string>words={"e","a","b"};
    vector<int>groups={0,0,1};
    // Output: ["a","b","c"]
    vector<string>words2={"a","b","c","d"};
    vector<int>groups2={1,0,1,1};
    return 0;
}