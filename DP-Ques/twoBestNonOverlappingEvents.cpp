// LC - 2054 - Medium - Two Best Non-Overlapping Events
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
class DP{
    int n;
    int dp[100001][3];
    int binarySearch(vector<vector<int>>&events,int endTime){
        int l=0,r=n-1;
        int ans=n;

        while(l<=r){
            int mid=l+(r-l)/2;

            if(events[mid][0]>endTime){
                ans=mid;
                r=mid-1;
            } else{
                l=mid+1;
            }
        }
        return ans;
    }
    int solve(vector<vector<int>>&events,int count,int i){
        if(i>=n || count>=2){
            return 0;
        }

        if(dp[i][count]!=-1) return dp[i][count];

        int nextValidEventIndex=binarySearch(events,events[i][1]);

        int take=events[i][2]+solve(events,count+1,nextValidEventIndex);
        int skip=solve(events,count,i+1);

        return dp[i][count]=max(take,skip);
    }
    public:
    int maxTwoEvents(vector<vector<int>>&events){
        n=events.size();
        
        memset(dp,-1,sizeof(dp));
        sort(begin(events),end(events));

        return solve(events,0,0);
    }
};
int main(){
    // Output: 4
    vector<vector<int>>events={{1,3,2},{4,5,2},{2,4,3}};
    // Output: 5
    vector<vector<int>>events2={{1,3,2},{4,5,2},{1,5,5}};
    // Output: 8
    vector<vector<int>>events3={{1,5,3},{1,5,1},{6,6,5}};

    DP sol;
    cout<<sol.maxTwoEvents(events)<<endl;
    cout<<sol.maxTwoEvents(events2)<<endl;
    cout<<sol.maxTwoEvents(events3);
    return 0;
}