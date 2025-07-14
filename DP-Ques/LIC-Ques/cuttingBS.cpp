// GFG - Cutting Binary String
#include<iostream>
#include<vector>
using namespace std;
class DP{
    bool isPowerOfFive(string &s){
        if(s[0]=='0') return 0;
        
        int num=0;
        for(char &ch:s){
            num=num*2+(ch-'0');
        }
        
        while(num>1 && num%5==0){
            num/=5;
        }
        return num==1;
    }
    public:
    int cuts(string s){
        int n=s.length();
        
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                string subStr=s.substr(j,i-j);
                
                if(isPowerOfFive(subStr) && dp[j]!=INT_MAX){
                    dp[i]=min(dp[i],dp[j]+1);
                }
            }
        }
        return dp[n]==INT_MAX?-1:dp[n];
    }
};
int main(){
    // Output: 3
    string s="101101101";
    // Output: 1
    string s2="1111101";
    // Output: -1
    string s3="00000";

    DP sol;
    cout<<sol.cuts(s)<<endl;
    cout<<sol.cuts(s2)<<endl;
    cout<<sol.cuts(s3);
    return 0;
}