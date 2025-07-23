// LC - 1642 - Medium - Furthest Building You Can Reach
// ACCEPTED using Heap
#include<iostream>
#include<vector>
using namespace std;
// MLE - NOT ACCEPTED
class DP{
    int n;
    vector<vector<int>>dp;
    int solve(vector<int>&heights,int bricks,int ladders,int idx){
        if(idx>=n-1) return 0;

        if(dp[bricks][ladders]!=-1) return dp[bricks][ladders];

        // Current h is greater so no need to do anything
        if(heights[idx]>=heights[idx+1]){
            return dp[bricks][ladders]=1+solve(heights,bricks,ladders,idx+1);
        }

        // We have use one of left items
        int usingBricks=0;
        int usingLadders=0;

        if(bricks>=heights[idx+1]-heights[idx]){
            usingBricks=1+solve(heights,bricks-(heights[idx+1]-heights[idx]),ladders,idx+1);
        }
        if(ladders>0){
            usingLadders=1+solve(heights,bricks,ladders-1,idx+1);
        }

        return dp[bricks][ladders]=max(usingBricks,usingLadders);
    }
    public:
    int furthestBuilding(vector<int>&heights,int bricks,int ladders){
        n=heights.size();

        dp=vector<vector<int>>(bricks+1,vector<int>(ladders+1,-1));

        return solve(heights,bricks,ladders,0);
    }
};
int main(){
    // Output: 4
    vector<int>heights={4,2,7,6,9,14,12};
    int bricks=5,ladders=1;
    // Output: 7
    vector<int>heights2={4,12,2,7,3,18,20,3,19};
    int bricks2=10,ladders2=2;
    // Output: 3
    vector<int>heights3={14,3,19,3};
    int bricks3=17,ladders3=0;

    DP sol;
    cout<<sol.furthestBuilding(heights,bricks,ladders)<<endl;
    cout<<sol.furthestBuilding(heights2,bricks2,ladders2)<<endl;
    cout<<sol.furthestBuilding(heights3,bricks3,ladders3);
    return 0;
}