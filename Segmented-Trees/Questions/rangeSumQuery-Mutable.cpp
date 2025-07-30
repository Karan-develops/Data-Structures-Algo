// LC - 307 - Medium - Range Sum Query - Mutable
#include<iostream>
#include<vector>
using namespace std;
class Segment_Tree{
    int n;
    vector<int>segTree;

    void buildSegTree(vector<int>&nums,int i,int l,int r){
        if(l==r){
            segTree[i]=nums[r];
            return;
        }

        int mid=l+(r-l)/2;

        buildSegTree(nums,2*i+1,l,mid);
        buildSegTree(nums,2*i+2,mid+1,r);

        segTree[i]=segTree[2*i+1]+segTree[2*i+2];
    }

    void updateSegTree(int i,int l,int r,int idx,int val){
        if(l==r){
            segTree[i]=val;
            return;
        }

        int mid=l+(r-l)/2;

        if(idx<=mid){
            updateSegTree(2*i+1,l,mid,idx,val);
        } else{
            updateSegTree(2*i+2,mid+1,r,idx,val);
        }

        segTree[i]=segTree[2*i+1]+segTree[2*i+2];
    }

    int solve(int i,int l,int r,int queryLeft,int queryRight){
        if(l>queryRight || r<queryLeft){
            return 0;
        }

        if(l>=queryLeft && r<=queryRight){
            return segTree[i];
        }

        int mid=l+(r-l)/2;

        return solve(2*i+1,l,mid,queryLeft,queryRight)+
               solve(2*i+2,mid+1,r,queryLeft,queryRight);
    }
    public:
    Segment_Tree(vector<int>&nums){
        n=nums.size();

        segTree.resize(4*n);
        buildSegTree(nums,0,0,n-1);
    }
    
    void update(int index,int val){
        updateSegTree(0,0,n-1,index,val);
    }
    
    int sumRange(int left,int right){
        return solve(0,0,n-1,left,right);
    }
};
/*
Example 1:
Input:
["NumArray", "sumRange", "update", "sumRange"]
[[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
Output:
[null, 9, null, 8]
*/