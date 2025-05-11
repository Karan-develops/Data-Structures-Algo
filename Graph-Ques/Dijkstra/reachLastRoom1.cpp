// LC - 3341 - Medium - Find Minimum Time to Reach Last Room I
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution{
    typedef pair<int,pair<int,int>>P;
    vector<vector<int>>directions{{0,1},{1,0},{-1,0},{0,-1}};
    public:
    int minTimeToReach(vector<vector<int>>&moveTime){
        int m=moveTime.size(),n=moveTime[0].size();

        priority_queue<P,vector<P>,greater<P>>pq;
        vector<vector<int>>ans(m,vector<int>(n,INT_MAX));

        pq.push({0,{0,0}});
        ans[0][0]=0;

        while(!pq.empty()){
            int currTime=pq.top().first;
            auto cell=pq.top().second;

            int i=cell.first;
            int j=cell.second;
            pq.pop();

            if(i==m-1 && j==n-1) return currTime;

            for(auto &dir:directions){
                int i_=i+dir[0];
                int j_=j+dir[1];

                if(i_>=0 && i_<m && j_>=0 && j_<n){
                    int wait=max(moveTime[i_][j_]-currTime,0);
                    int arrTime=currTime+wait+1;
                    
                    if(ans[i_][j_]>arrTime){
                        ans[i_][j_]=arrTime;
                        pq.push({arrTime,{i_,j_}});
                    }
                }
            }
        }
        return -1;
    }
};
int main(){
    // Output: 6
    vector<vector<int>>moveTime={{0,4},{4,4}};
    // Output: 3
    vector<vector<int>>moveTime2={{0,0,0},{0,0,0}};
    // Output: 3
    vector<vector<int>>moveTime3={{0,1},{1,2}};
    Solution sol;
    cout<<sol.minTimeToReach(moveTime)<<endl;
    cout<<sol.minTimeToReach(moveTime2)<<endl;
    cout<<sol.minTimeToReach(moveTime3);
    return 0;
}