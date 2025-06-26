// LC - 2311 - Medium - Longest Binary Subsequence Less Than or Equal to K
// 2 Approaches - Bits - Recursion
#include<iostream>
using namespace std;
class BitMagic{
    int n;
    int solve(string &s,int k,int i){
        if(i<0) return 0;

        int take=0;
        int bit=s[i]-'0';
        long long value=(bit==1?(1LL<<(n-i-1)):0);

        if(value<=k){
            take=1+solve(s,k-value,i-1);
        }

        int skip=solve(s,k,i-1);
        return max(take, skip);
    }
    public:
    // Approach 1
    int longestSubsequence(string s,int k){
        int ans=0;
        long long power=1;

        for(int i=s.length()-1;i>=0;i--){
            // Zeroes doesn't impact anything so include everytime
            if(s[i]=='0') ans++;
            // 1*power OR s[i]*power -> it is 1 so just power will work
            else if(power<=k){
                k-=power;
                ans++;
            }

            if(power<=k) power<<=1;
        }
        return ans;
    }
    // Approach 2
    int longestSubsequenceRecursion(string &s,int k){
        n=s.length();
        return solve(s,k,n-1);
    }
};
int main(){
    // Output: 5
    string s="1001010";
    int k=5;
    // Output: 6
    string s2="00101001";
    int k2=1;

    BitMagic sol;
    cout<<sol.longestSubsequence(s,k)<<endl;
    cout<<sol.longestSubsequence(s2,k2);
    return 0;
}