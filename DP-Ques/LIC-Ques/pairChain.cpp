// LC - 646 - Medium - Maximum Length of Pair Chain
// 2 Approaches
// TODO: Will Update Top Down Approach Soon....
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class BottomUp{
    public:
    int findLongestChain(vector<vector<int>>&pairs){
        int n=pairs.size();

        sort(begin(pairs),end(pairs));

        vector<int>dp(n,1);
        int ans=1;

        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                if(pairs[j][1]<pairs[i][0]){
                    dp[i]=max(dp[i],dp[j]+1);
                    ans=max(ans,dp[i]);
                }
            }
        }
        return ans;
    }
};
int main(){
    // Output: 2
    vector<vector<int>>pairs={{1,2},{2,3},{3,4}};
    // Output: 3
    vector<vector<int>>pairs2={{1,2},{7,8},{4,5}};

    BottomUp sol;
    cout<<sol.findLongestChain(pairs)<<endl;
    cout<<sol.findLongestChain(pairs2);
    return 0;
}