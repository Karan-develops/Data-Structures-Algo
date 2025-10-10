// LC - 3147 - Medium - Taking Maximum Energy From the Mystic Dungeon
// 2 Approaches
#include<iostream>
#include<vector>
using namespace std;
// Approach 1 - Top Down (Rec+Memo)
class DP{
    int n;
    vector<int>dp;
    int solve(vector<int>&energy,int &k,int idx){
        if(idx>=n){
            return 0;
        }

        if(dp[idx]!=INT_MIN) return dp[idx];

        dp[idx]=energy[idx]+solve(energy,k,idx+k);

        return dp[idx];
    }
    public:
    int maximumEnergy(vector<int>&energy,int k){
        n=energy.size();
        dp.assign(n,INT_MIN);

        int ans=INT_MIN;

        for(int i=0;i<n;i++){
            ans=max(ans,solve(energy,k,i));
        }

        return ans;
    }
};
// Approach 2 - Bottom Up
class BottomUp{
    public:
    int maximumEnergy(vector<int>&energy,int k){
        int n=energy.size();

        // Fill dp values from the back
        for(int i=n-1;i>=0;i--){
            if(i+k<n){
                energy[i]+=energy[i+k];
            }
        }

        int ans=energy[0];

        for(int i=1;i<n;i++){
            ans=max(ans,energy[i]);
        }

        return ans;
    }
};
int main(){
    // Output: 3
    vector<int>energy={5,2,-10,-5,1};
    int k=3;
    // Output: -1
    vector<int>energy2={-2,-3,-1};
    int k2=2;

    DP sol;
    cout<<sol.maximumEnergy(energy,k)<<endl;
    cout<<sol.maximumEnergy(energy2,k2);
    return 0;
}