// LC - 1930 - Medium - Unique Length-3 Palindromic Subsequences
// 2 Approaches
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
// Approach 1
int countPalindromicSubsequence(string s){
    int n=s.length();
    unordered_set<char>unique_letters;
    
    for(char &ch:s){
        unique_letters.insert(ch);
    }
    
    int ans=0;
    
    for(char letter:unique_letters){
        int left_idx=-1;
        int right_idx=-1;
        
        for(int i=0;i<n;i++){
            if(s[i]==letter){
                if(left_idx==-1){
                    left_idx=i;
                }
                right_idx=i;
            }
        }
                        
        unordered_set<char>st;
        for(int middle=left_idx+1;middle<=right_idx-1;middle++){
            st.insert(s[middle]);
        }

        ans+=st.size();
    }
    return ans;
}
// Approach 2 - Precompute indices
int countPalindromicSubsequencePrecompute(string s){
    int n=s.length();
    vector<pair<int,int>>indices(26,{-1,-1});
    
    for(int i=0;i<n;i++){
        char ch=s[i];
        int idx=ch-'a';
        
        if(indices[idx].first==-1){
            indices[idx].first=i;
        }
        
        indices[idx].second=i;
    }
    
    int ans=0;

    for(int i=0;i<26;i++){
        if(indices[i]==make_pair(-1,-1)){
            continue;
        }
        
        unordered_set<char>st;
        for(int middle=indices[i].first+1;middle<=indices[i].second-1;middle++){
            st.insert(s[middle]);
        }
        
        ans+=st.size();
    }
    return ans;
}
int main(){
    // Output: 3
    string s="aabca";
    // Output: 0
    string s2="adc";
    // Output: 4
    string s3="bbcbaba";
    cout<<countPalindromicSubsequence(s)<<endl;
    cout<<countPalindromicSubsequence(s2)<<endl;
    cout<<countPalindromicSubsequence(s3);
    return 0;
}