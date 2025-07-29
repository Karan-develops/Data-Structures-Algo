// Range Maximum Index Query
// Now store indices in Segment Tree instead of Elements
#include<iostream>
#include<vector>
using namespace std;
class Segment_Tree{
    vector<int>segTree;
    void buildSegTree(vector<int>&nums,int i,int l,int r){
        if(l==r){
            // segTree[i]=nums[r];
            segTree[i]=r; // Store Index
            return;
        }

        int mid=l+(r-l)/2;

        buildSegTree(nums,2*i+1,l,mid);
        buildSegTree(nums,2*i+2,mid+1,r);

        // segTree[i]=segTree[2*i+1]+segTree[2*i+2];
        int leftIdx=segTree[2*i+1];
        int rightIdx=segTree[2*i+2];

        segTree[i]=(nums[leftIdx]>=nums[rightIdx])?leftIdx:rightIdx;
    }
    int querySegmentTree(vector<int>&nums,int i,int l,int r,int start,int end){
        if(l>end || r<start){
            return -1;
        }

        if(l>=start && r<=end){
            return segTree[i];
        }

        int mid=l+(r-l)/2;

        int leftIdx=querySegmentTree(nums,2*i+1,l,mid,start,end);
        int rightIdx=querySegmentTree(nums,2*i+2,mid+1,r,start,end);

        if(leftIdx==-1) return rightIdx;
        if(rightIdx==-1) return leftIdx;

        return (nums[leftIdx]>=nums[rightIdx])?leftIdx:rightIdx;
    }
    public:
    int rmiq(vector<int>&nums,int start,int end){
        int n=nums.size();

        segTree.resize(4*n);
        buildSegTree(nums,0,0,n-1);

        return querySegmentTree(nums,0,0,n-1,start,end);
    }
};
int main(){
    vector<int>nums={1,3,5,7,9,11};

    Segment_Tree tree;
    cout<<tree.rmiq(nums,1,4);

    return 0;
}