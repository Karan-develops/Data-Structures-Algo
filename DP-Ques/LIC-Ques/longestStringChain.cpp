// LC - 1048 - Medium - Longest String Chain
// 2 Approaches
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
// Approach 1 - LIS ( Bottom Up )
class DP{
    bool checkPredecessor(string &iStr,string &jStr){
        if(iStr.length()!=jStr.length()+1) return false;

        int m=iStr.length(),n=jStr.length();
        int i=0,j=0;

        while(i<m && j<n){
            if(iStr[i]==jStr[j]) i++,j++;
            else i++;
        }
        return j==n;
    }
    public:
    int longestStrChain(vector<string>&words){
        int n=words.size();

        auto lambda=[](string &a,string &b){
            return a.length()<b.length();
        };

        sort(begin(words),end(words),lambda);

        vector<int>dp(n,1);
        int ans=1;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(checkPredecessor(words[i],words[j]) && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    ans=max(ans,dp[i]);
                }
            }
        }
        return ans;
    }
};
// Approach 2 - Recursion + Memo ( Top Down )
class TopDown{
    int n;
    int dp[1001][1001];
    bool checkPredecessor(string &prev,string &curr){
        int M=prev.length(),N=curr.length();
        
        if(M>=N || N-M!=1) return false;
        
        int i=0,j=0;

        while(i<M && j<N){
            if(prev[i]==curr[j]){
                i++;
            }
            j++;
        }
        return i==M;
    }
    int solve(vector<string>&words,int prev,int i){
        if(i>=n) return 0;

        if(prev!=-1 && dp[prev][i]!=-1) return dp[prev][i];

        int take=0;
        if(prev==-1 || checkPredecessor(words[prev],words[i])){
            take=1+solve(words,i,i+1);
        }

        int skip=solve(words,prev,i+1);
        
        if(prev!=-1){
            dp[prev][i]=max(take,skip);
        }

        return max(take,skip);
    }
    public:
    int longestStrChain(vector<string>&words){
        n=words.size();

        auto lambda=[](string &a,string &b){
            return a.length()<b.length();
        };

        sort(begin(words),end(words),lambda);

        memset(dp,-1,sizeof(dp));

        return solve(words,-1,0);
    }
};
int main(){
    // Output: 4
    vector<string>words={"a","b","ba","bca","bda","bdca"};
    // Output: 5
    vector<string>words2={"xbc","pcxbcf","xb","cxbc","pcxbc"};
    // Output: 1
    vector<string>words3={"abcd","dbqca"};

    DP sol;
    cout<<sol.longestStrChain(words)<<endl;
    cout<<sol.longestStrChain(words2)<<endl;
    cout<<sol.longestStrChain(words3);
    return 0;
}