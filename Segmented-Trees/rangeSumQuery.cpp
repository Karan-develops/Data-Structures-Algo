// Find Sum of a Given Range
#include<iostream>
#include<vector>
using namespace std;
class Segment_Tree{
    void buildSegTree(vector<int>&nums,vector<int>&segTree,int i,int l,int r){
        if(l==r){
            segTree[i]=nums[r];
            return;
        }

        int mid=l+(r-l)/2;

        buildSegTree(nums,segTree,2*i+1,l,mid);
        buildSegTree(nums,segTree,2*i+2,mid+1,r);

        segTree[i]=segTree[2*i+1]+segTree[2*i+2];
    }
    // 3 Cases
    int solve(vector<int>&segTree,int i,int l,int r,int givenRangeStart,int givenRangeEnd){
        // Case 1 : Completed Out of Range
        if(l>givenRangeEnd || r<givenRangeStart){
            return 0;
        }

        // Case 2 : Completely In Range
        if(l>=givenRangeStart && r<=givenRangeEnd){
            return segTree[i];
        }
        
        // Case 3 : Partially In Range
        int mid=l+(r-l)/2;

        return solve(segTree,2*i+1,l,mid,givenRangeStart,givenRangeEnd)+
               solve(segTree,2*i+2,mid+1,r,givenRangeStart,givenRangeEnd);
    }
    public:
    int rangeSumQuery(vector<int>&nums,int l,int r){
        int n=nums.size();

        vector<int>segTree(4*n);
        buildSegTree(nums,segTree,0,0,n-1);

        return solve(segTree,0,0,n-1,l,r);
    }
};
int main(){
    vector<int>nums={1,3,5,7,9,11};

    Segment_Tree tree;
    cout<<tree.rangeSumQuery(nums,2,4);

    return 0;
}