// LC - 1751 - HARD - Maximum Number of Events That Can Be Attended II
// 2 Approaches - Linear - Binary Search
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class DP{
    int n;
    vector<vector<int>>dp;
    int solve(vector<vector<int>>&events,int k,int i){
        if(i>=n || k<=0){
            return 0;
        }

        if(dp[i][k]!=-1) return dp[i][k];
        
        int start=events[i][0];
        int end=events[i][1];
        int val=events[i][2];

        int j=i+1;
        for(;j<n;j++){
            if(events[j][0]>events[i][1]) break;
        }

        int take=val+solve(events,k-1,j);
        int skip=solve(events,k,i+1);

        return dp[i][k]=max(take,skip);
    }
    public:
    int maxValue(vector<vector<int>>&events,int k){
        n=events.size();
        dp.resize(n+1,vector<int>(k+1,-1));
        
        sort(begin(events),end(events));

        return solve(events,k,0);
    }
};
class BinarySearch{
    int n;
    vector<vector<int>>dp;
    int solve(vector<vector<int>>&events,int k,int i){
        if(i>=n || k<=0){
            return 0;
        }

        if(dp[i][k]!=-1) return dp[i][k];
        
        int start=events[i][0];
        int end=events[i][1];
        int val=events[i][2];

        vector<int>temp={end,INT_MAX,INT_MAX};
        int j=upper_bound(events.begin(),events.end(),temp)-events.begin();

        int take=val+solve(events,k-1,j);
        int skip=solve(events,k,i+1);

        return dp[i][k]=max(take,skip);
    }
    public:
    int maxValue(vector<vector<int>>& events,int k){
        n=events.size();
        dp.resize(n+1,vector<int>(k+1,-1));
        
        sort(begin(events),end(events));

        return solve(events,k,0);
    }
};
int main(){
    // Output: 7
    vector<vector<int>>events={{1,2,4},{3,4,3},{2,3,1}};
    int k=2;
    // Output: 10
    vector<vector<int>>events2={{1,2,4},{3,4,3},{2,3,10}};
    int k2=2;
    // Output: 9
    vector<vector<int>>events3={{1,1,1},{2,2,2},{3,3,3},{4,4,4}};
    int k3=3;

    DP sol;
    cout<<sol.maxValue(events,k)<<endl;
    cout<<sol.maxValue(events2,k2)<<endl;
    cout<<sol.maxValue(events3,k3);
    return 0;
}