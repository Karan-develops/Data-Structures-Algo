// LC - 2901 - Medium - Longest Unequal Adjacent Groups Subsequence II
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class LIS{
    bool checkHamming(string &s1,string &s2){
        if(s1.length()!=s2.length()) return false;
        bool flag=true;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i] && !flag) return false;
            if(s1[i]!=s2[i]) flag=false;
        }
        return true;
    }
    public:
    vector<string> getWordsInLongestSubsequence(vector<string>&words,vector<int>&groups){
        int n=words.size();
        vector<int>dp(n,1);
        vector<int>parent(n,-1);
        int longestSubSq=1;
        // Starting from 0 instead of -1 bcoz if there is only 1 word then it should be ans.
        int longestSubSqIdx=0;

        // T.C --> O(n^2 * L)
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(groups[i]!=groups[j] && checkHamming(words[i],words[j])){
                    if(dp[i]<dp[j]+1){
                        parent[i]=j;
                        dp[i]=dp[j]+1;
                        if(longestSubSq<dp[i]){
                            longestSubSq=dp[i];
                            longestSubSqIdx=i;
                        }
                    }
                }
            }
        }
        vector<string>ans;
        while(longestSubSqIdx!=-1){
            ans.push_back(words[longestSubSqIdx]);
            longestSubSqIdx=parent[longestSubSqIdx];
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};
int main(){
    // Output: ["bab","cab"]
    vector<string>words={"bab","dab","cab"};
    vector<int>groups={1,2,2};
    // Output: ["a","b","c","d"]
    vector<string>words2={"a","b","c","d"};
    vector<int>groups2={1,2,3,4};
    LIS lis;
    vector<string>ans=lis.getWordsInLongestSubsequence(words2,groups2);
    for(string &s:ans) cout<<s<<" ";
    return 0;
}