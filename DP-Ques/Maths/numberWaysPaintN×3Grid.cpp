// LC - 1411 - HARD - Number of Ways to Paint N × 3 Grid
#include<iostream>
#include<vector>
using namespace std;
class DP{
    int M=1e9+7;
    vector<vector<int>>dp;
    // 12 possible first rows
    string states[12]={"RYG","RGY","RYR","RGR","YRG","YGR","YGY","YRY","GRY","GYR","GRG","GYG"};
    int solve(int n,int prev){
        if(n==0) return 1;
        
        if(dp[n][prev]!=-1) return dp[n][prev];

        int ans=0;
        string last=states[prev];

        for(int curr=0;curr<12;curr++){
            if(curr==prev) continue;
            
            string currPat=states[curr];
            bool conflict=false;
            
            for(int col=0;col<3;col++){
                if(currPat[col]==last[col]){
                    conflict=true;
                    break;
                }
            }

            if(!conflict){
                ans=(ans+solve(n-1,curr))%M;
            }
        }

        return dp[n][prev]=ans;
    }
    public:
    int numOfWays(int n){
        dp.resize(n,vector<int>(12,-1));
        int ans=0;

        // chossing 1st row
        for(int i=0;i<12;i++){
            // now remaining n-1 rows painting
            ans=(ans+solve(n-1,i))%M;
        }

        return ans;
    }
};
int main(){
    // Output: 12
    int n=1;
    // Output: 30228214
    int n2=5000;

    DP sol;
    cout<<sol.numOfWays(n)<<endl;
    cout<<sol.numOfWays(n2);
    return 0;
}