// Segment Tree - Check Readme First
#include<iostream>
#include<vector>
using namespace std;
class Segment_Tree{
    public:
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
};
int main(){
    vector<int>nums={1,3,5,7,9,11};
    int n=nums.size();

    vector<int>segTree(4*n);

    Segment_Tree tree;
    tree.buildSegTree(nums,segTree,0,0,n-1);

    for(int &i:segTree) cout<<i<<" ";
    return 0;
}