// LC - 474 - Medium - Ones and Zeroes
#include<iostream>
#include<vector>
using namespace std;
class DP{
    int N;
    vector<vector<vector<int>>>dp;
    int solve(vector<pair<int,int>>&count,int m,int n,int i){
        if((i>=N) || (m<0 && n<0)){
            return 0;
        }

        if(dp[m][n][i]!=-1) return dp[m][n][i];

        int take=0;
        if(count[i].first<=m && count[i].second<=n){
            take=1+solve(count,m-count[i].first,n-count[i].second,i+1);
        }

        int skip=solve(count,m,n,i+1);

        return dp[m][n][i]=max(take,skip);
    }
    public:
    int findMaxForm(vector<string>&strs,int m,int n){
        N=strs.size();

        vector<pair<int,int>>count;

        for(string &s:strs){
            int zeroes=0;
            int ones=0;

            for(const char &ch:s){
                if(ch=='0') zeroes++;
                else ones++;
            }

            count.push_back({zeroes,ones});
        }

        dp.assign(m+1,vector<vector<int>>(n+1,vector<int>(N+1,-1)));

        return solve(count,m,n,0);
    }
};
int main(){
    // Output: 4
    vector<string>strs={"10","0001","111001","1","0"};
    int m=5,n=3;
    // Output: 2
    vector<string>strs2={"10","0","1"};
    int m2=1,n2=1;

    DP sol;
    cout<<sol.findMaxForm(strs,m,n)<<endl;
    cout<<sol.findMaxForm(strs2,m2,n2);
    return 0;
}