// LC - 2014 - HARD - Longest Subsequence Repeated k Times
#include<iostream>
#include<vector>
using namespace std;
class BackTracking{
    bool isSubsequence(string &s,string &curr,int k){
        int i=0,j=0;
        int m=s.length(),n=curr.length();

        while(i<m && j<n*k){
            if(s[i]==curr[j%n]) j++;
            i++;
        }
        return j==n*k;
    }
    void solve(vector<bool>&canUse,vector<int>&requiredFreq,int k,int maxLen,string &s,string &ans,string &curr){
        if(curr.length()>maxLen){
            return;
        }

        if((curr.length()>ans.length() || (curr.length()==ans.length() && curr>ans)) 
            && isSubsequence(s,curr,k)){
                ans=curr;
        }

        for(int i=0;i<26;i++){
            if(canUse[i]==false || requiredFreq[i]==0) continue;

            // Do
            curr.push_back(i+'a');
            requiredFreq[i]--;

            // Explore
            solve(canUse,requiredFreq,k,maxLen,s,ans,curr);

            // Undo
            curr.pop_back();
            requiredFreq[i]++;
        }
    }
    public:
    string longestSubsequenceRepeatedK(string s,int k){
        int n=s.length();

        vector<int>freq(26,0);
        for(char &ch:s) freq[ch-'a']++;

        vector<bool>canUse(26,false);
        vector<int>requiredFreq(26,0);
        for(int i=0;i<26;i++){
            if(freq[i]>=k){
                canUse[i]=true;
                requiredFreq[i]=freq[i]/k;
            }
        }

        int maxLen=n/k;

        string ans;
        string curr;

        solve(canUse,requiredFreq,k,maxLen,s,ans,curr);

        return ans;
    }
};
int main(){
    // Output: "let"
    string s="letsleetcode";
    int k=2;
    // Output: "b"
    string s2="bb";
    int k2=2;
    // Output: ""
    string s3="ab";
    int k3=2;

    BackTracking sol;
    cout<<sol.longestSubsequenceRepeatedK(s,k)<<endl;
    cout<<sol.longestSubsequenceRepeatedK(s2,k2)<<endl;
    cout<<sol.longestSubsequenceRepeatedK(s3,k3);
    return 0;
}