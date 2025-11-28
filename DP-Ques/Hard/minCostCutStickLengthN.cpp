// GFG - HARD - Minimum Cost to Cut a Stick of length N
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class DP{
    vector<vector<int>>dp;
    int solve(vector<int>&cuts,int i,int j){
        if(j-i<=1) return 0;  // No cut possible
    
        if(dp[i][j]!=-1) return dp[i][j];
    
        int cost=INT_MAX;
    
        for(int k=i+1;k<j;k++){
            int temp=solve(cuts,i,k)+solve(cuts,k,j)+(cuts[j]-cuts[i]);
            
            cost=min(cost,temp);
        }
    
        return dp[i][j]=cost;
    }
    public:
    int minCutCost(int n,vector<int>&cuts){
        cuts.push_back(0);
        cuts.push_back(n);
        
        sort(begin(cuts),end(cuts));
    
        int m=cuts.size();
        dp.assign(m,vector<int>(m,-1));
    
        return solve(cuts,0,m-1);
    }
};
int main(){
    // Output: 20
    int n=10;
    vector<int>cuts={2,4,7};
    // Output: 19
    int n2=8;
    vector<int>cuts2={1,6,3,5};

    DP sol;
    cout<<sol.minCutCost(n,cuts)<<endl;
    cout<<sol.minCutCost(n2,cuts2);
    return 0;
}