// LC - 960 - HARD - Delete Columns to Make Sorted III
// Also in String DP
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
class DP{
    public:
    int minDeletionSize(vector<string>&strs){
        int m=strs.size();
        int n=strs[0].length();

        // dp[i] = LIS ending at index i
        vector<int>dp(n,1);

        int LIS=1;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                bool valid = true;

                for(int k=0;k<m;k++){
                    if(strs[k][j]>strs[k][i]){
                        valid=false;
                        break;
                    }
                }

                if(valid){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }

            LIS=max(LIS,dp[i]);
        }

        return n-LIS;
    }
};
int main(){
    // Output: 3
    vector<string>strs={"babca","bbazb"};
    // Output: 4
    vector<string>strs2={"edcba"};
    // Output: 0
    vector<string>strs3={"ghi","def","abc"};

    DP sol;
    cout<<sol.minDeletionSize(strs)<<endl;
    cout<<sol.minDeletionSize(strs2)<<endl;
    cout<<sol.minDeletionSize(strs3);
    return 0;
}