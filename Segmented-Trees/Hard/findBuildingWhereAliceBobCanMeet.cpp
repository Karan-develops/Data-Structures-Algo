// LC - 2940 - HARD - Find Building Where Alice and Bob Can Meet
// RMIQ 3rd Variant - Binary Search
#include<iostream>
#include<vector>
using namespace std;
class Segment_Tree{
    int n;
    vector<int>segTree;
    void buildSegTree(vector<int>&nums,int i,int l,int r){
        if(l==r){
            // Store index
            segTree[i]=r;
            return;
        }

        int mid=l+(r-l)/2;

        buildSegTree(nums,2*i+1,l,mid);
        buildSegTree(nums,2*i+2,mid+1,r);

        segTree[i]=(nums[segTree[2*i+1]]>=nums[segTree[2*i+2]])?segTree[2*i+1]:segTree[2*i+2];
    }
    int querySegTree(vector<int>&nums,int i,int l,int r,int start,int end){
        if(l>end || r<start){
            return -1;
        }

        if(l>=start && r<=end){
            return segTree[i];
        }

        int mid=l+(r-l)/2;

        int leftIdx=querySegTree(nums,2*i+1,l,mid,start,end);
        int rightIdx=querySegTree(nums,2*i+2,mid+1,r,start,end);

        if(leftIdx==-1) return rightIdx;
        if(rightIdx==-1) return leftIdx;

        return (nums[leftIdx]>=nums[rightIdx])?leftIdx:rightIdx;
    }
    int rmiq(vector<int>&nums,int l,int r){
        return querySegTree(nums,0,0,n-1,l,r);
    }
    public:
    vector<int> leftmostBuildingQueries(vector<int>&heights,vector<vector<int>>&queries){
        n=heights.size();

        // Build Segment Tree
        segTree.clear();
        segTree.resize(4*n);
        buildSegTree(heights,0,0,n-1);

        vector<int>ans;

        for(auto &vec:queries){
            int alice=min(vec[0],vec[1]);
            int bob=max(vec[0],vec[1]);

            if(alice==bob || heights[alice]<heights[bob]){
                ans.push_back(bob);
                continue;
            }

            int l=bob+1;
            int r=n-1;
            int ans_idx=INT_MAX;

            while(l<=r){
                int mid=l+(r-l)/2;
                int idx=rmiq(heights,l,mid);

                if(max(heights[bob],heights[alice])<heights[idx]){
                    r=mid-1;
                    ans_idx=min(ans_idx,idx);
                } else{
                    l=mid+1;
                }
            }

            if(ans_idx==INT_MAX){
                ans.push_back(-1);
            } else{
                ans.push_back(ans_idx);
            }
        }
        return ans;
    }
};
int main(){
    // Output: [2,5,-1,5,2]
    vector<int>heights={6,4,8,5,2,7};
    vector<vector<int>>queries={{0,1},{0,3},{2,4},{3,4},{2,2}};
    // Output: [7,6,-1,4,6]
    vector<int>heights2={5,3,8,2,6,1,4,6};
    vector<vector<int>>queries2={{0,7},{3,5},{5,2},{3,0},{1,6}};

    Segment_Tree sol;
    vector<int>ans=sol.leftmostBuildingQueries(heights,queries);

    for(int &i:ans) cout<<i<<" ";
    return 0;
}