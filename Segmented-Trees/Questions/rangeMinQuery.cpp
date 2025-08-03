// GFG - Range Minimum Query
// T.C : O(q*log(n))
// S.C : O(4*n)
#include<iostream>
#include<vector>
using namespace std;
class Segment_Tree{
    public:
    void buildSegTree(int arr[],int segTree[],int i,int l,int r){
        if(l==r){
            segTree[i]=arr[r];
            return;
        }
        
        int mid=l+(r-l)/2;
        
        buildSegTree(arr,segTree,2*i+1,l,mid);
        buildSegTree(arr,segTree,2*i+2,mid+1,r);
        
        segTree[i]=min(segTree[2*i+1],segTree[2*i+2]);
    }
    int solve(vector<int>&segTree,int i,int l,int r,int queryLeft,int queryRight){
        if(l>queryRight || r<queryLeft){
            return INT_MAX;
        }
        
        if(l>=queryLeft && r<=queryRight){
            return segTree[i];
        }
        
        int mid=l+(r-l)/2;
        
        return min(solve(segTree,2*i+1,l,mid,queryLeft,queryRight),
                solve(segTree,2*i+2,mid+1,r,queryLeft,queryRight));
    }
    public:
    int *constructST(int arr[],int n){
        int *segTree=new int[4*n];
        
        buildSegTree(arr,segTree,0,0,n-1);
        return segTree;
    }
    int RMQ(vector<int>st,int n,int a,int b){
        return solve(st,0,0,n-1,a,b);
    }
};