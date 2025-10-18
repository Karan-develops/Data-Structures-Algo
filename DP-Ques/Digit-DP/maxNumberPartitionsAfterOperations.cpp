// LC - 3003 - HARD - Maximize the Number of Partitions After Operations
// 2 Approaches
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
// Approach 1 - Digit DP - TLE
class DP{
    int n,K;
    // Storing in int instead of vector<int>v(26,0) or map
    int solve(string &s,bool canChange,int uniqueChars,int i){
        if(i>=n) return 0;

        int charIdx=s[i]-'a';
        int uniqueCharsUpdated=uniqueChars|(1<<charIdx);
        int uniqueCharsCount=__builtin_popcount(uniqueCharsUpdated);

        int ans=0;

        if(uniqueCharsCount>K){
            // uniqueCharsCount exceeded so start new partition
            ans=1+solve(s,canChange,(1<<charIdx),i+1);
        } else{
            ans=solve(s,canChange,uniqueCharsUpdated,i+1);
        }

        if(canChange){
            for(int ch=0;ch<26;ch++){
                int newSet=uniqueChars|(1<<ch);
                int newUniqueCharsCount=__builtin_popcount(newSet);

                 if(newUniqueCharsCount>K){
                    ans=max(ans,1+solve(s,false,(1<<ch),i+1));
                } else{
                    ans=max(ans,solve(s,false,newSet,i+1));
                }
            }
        }
        return ans;
    }
    public:
    int maxPartitionsAfterOperations(string s,int k){
        n=s.length();
        K=k;

        // +1 => for the last partition
        return solve(s,true,0,0)+1;
    }
};
// Approach 2 - Memoized Digit DP - ACCEPTED
class DigitDP{
    int n,K;
    unordered_map<long long,int>mp;
    // Storing in int instead of vector<int>v(26,0) or map
    int solve(string &s,bool canChange,int uniqueChars,long long i){
        long long key=(i<<27)|(uniqueChars<<1)|(canChange);

        if(mp.count(key)) return mp[key];

        if(i>=n) return 0;

        int charIdx=s[i]-'a';
        int uniqueCharsUpdated=uniqueChars|(1<<charIdx);
        int uniqueCharsCount=__builtin_popcount(uniqueCharsUpdated);

        int ans=0;

        if(uniqueCharsCount>K){
            // uniqueCharsCount exceeded so start new partition
            ans=1+solve(s,canChange,(1<<charIdx),i+1);
        } else{
            ans=solve(s,canChange,uniqueCharsUpdated,i+1);
        }

        if(canChange){
            for(int ch=0;ch<26;ch++){
                int newSet=uniqueChars|(1<<ch);
                int newUniqueCharsCount=__builtin_popcount(newSet);

                 if(newUniqueCharsCount>K){
                    ans=max(ans,1+solve(s,false,(1<<ch),i+1));
                } else{
                    ans=max(ans,solve(s,false,newSet,i+1));
                }
            }
        }
        return mp[key]=ans;
    }
    public:
    int maxPartitionsAfterOperations(string s,int k){
        n=s.length();
        K=k;
        mp.clear();

        // +1 => for the last partition
        return solve(s,true,0,0)+1;
    }
};
int main(){
    // Output: 3
    string s="accca";
    int k=2;
    // Output: 1
    string s2="aabaab";
    int k2=3;
    // Output: 4
    string s3="xxyz";
    int k3=1;

    DigitDP sol;
    cout<<sol.maxPartitionsAfterOperations(s,k)<<endl;
    cout<<sol.maxPartitionsAfterOperations(s2,k2)<<endl;
    cout<<sol.maxPartitionsAfterOperations(s3,k3);
    return 0;
}