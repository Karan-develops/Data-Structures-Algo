// LC - 2338 - HARD - Count the Number of Ideal Arrays
#include<iostream>
#include<vector>
using namespace std;
class Maths{
    const int M=1e9+7;
    int findPower(long long a,long long b){
        if(b==0) return 1;

        long long half=findPower(a,b/2);
        long long ans=(half*half)%M;

        if(b&1) ans=(ans*a)%M;
        return ans;
    }
    int modularNCR(int n,int r,vector<long long>&fact){
        if(r<0 || r>n) return 0;

        int b=(fact[r]*fact[n-r])%M;
        return (fact[n]*findPower(b,M-2))%M;
    }
    // Find the Sets, Eg: [2,4,8,16]
    void findSets(vector<vector<int>>&dp,vector<int>&count,int m){
        if(dp[m][1]!=0) return;

        dp[m][1]=1;
        count[1]++;

        for(int div=2;div<=m;div++){
            if(m%div==0){
                findSets(dp,count,m/div);

                for(int len=1;len<15;len++){
                    if(dp[m/div][len]!=0){
                        dp[m][len+1]+=dp[m/div][len];
                        count[len+1]+=dp[m/div][len];
                    }
                }
            }
        }
    }
    public:
    int idealArrays(int n,int maxValue){
        // 15 is Length Bcoz the highest value --> 10000 -> 2^14 it can go
        vector<vector<int>>dp(maxValue+1,vector<int>(15,0));
        vector<int>count(15,0);

        // Find the sets
        for(int val=1;val<=maxValue;val++){
            findSets(dp,count,val);
        }

        // Pre-Computing Factorial
        vector<long long>fact(n+1,1);
        for(int i=2;i<=n;i++){
            fact[i]=(fact[i-1]*i)%M;
        }

        long long ans=0;
        for(int len=1;len<15;len++){
            if(n<len) break;

            long long possibilities=modularNCR(n-1,len-1,fact);

            ans=(ans+(possibilities*count[len])%M)%M;
        }
        return (int)ans;
    }
};
int main(){
    // Output: 10
    int n=2,maxValue=5;
    // Output: 11
    int n2=5,maxValue2=3;

    Maths sol;
    cout<<sol.idealArrays(n,maxValue)<<endl;
    cout<<sol.idealArrays(n2,maxValue2);
    return 0;
}