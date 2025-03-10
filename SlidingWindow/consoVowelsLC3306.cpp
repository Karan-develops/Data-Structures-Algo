// LC - 3306 - Medium ( Level -> Hard)
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution{
    public:
    bool isVowel(char &ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }
    long long countOfSubstrings(string word,int k){
        int n=word.length();
        // S.C : O(5) constant
        unordered_map<char,int>mp;
        // Preprocessing to be able to find index of just next consonant
        vector<int>nextConsonent(n);
        int lastConsIdx=n;
        for(int i=n-1;i>=0;i--){
            nextConsonent[i]=lastConsIdx;
            // Consonent
            if(!isVowel(word[i])){
                lastConsIdx=i;
            }
        }
        int i=0,j=0;
        long long ans=0;
        int consonentCount=0;
        // T.C : O(2*n) ~ O(n) 
        while(j<n){
            char ch=word[j];
            if(isVowel(ch)) mp[ch]++;
            else consonentCount++;

            // consonents must be always == k
            while(consonentCount>k){
                char ch=word[i++];
                if(isVowel(ch)){
                    mp[ch]--;
                    if(mp[ch]==0) mp.erase(ch);
                } else consonentCount--;
            }
            //valid window
            while(i<n && mp.size()==5 && consonentCount==k){
                // it will tell me the next consonant after jth index
                int idx=nextConsonent[j];
                // most important part
                ans+=idx-j;
                char ch=word[i];
                if(isVowel(ch)){
                    mp[ch]--;
                    if(mp[ch]==0) mp.erase(ch);
                } else consonentCount--;
                i++;
            }
            j++;
        }
        return ans;
    }
};
int main(){
    string word1="aeioqq";
    int k1=1;
    string word2="aeiou";
    int k2=0;
    string word3="ieaouqqieaouqq";
    int k3=1;
    Solution sol;
    cout<<sol.countOfSubstrings(word1,k1)<<endl;
    cout<<sol.countOfSubstrings(word2,k2)<<endl;
    cout<<sol.countOfSubstrings(word3,k3)<<endl;
    return 0;
}