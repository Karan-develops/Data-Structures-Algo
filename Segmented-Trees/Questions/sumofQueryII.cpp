// GFG - Sum of Query II
// T.C : O(q*log(n))
// S.C : O(4*n)
#include<iostream>
#include<vector>
using namespace std;
class Segment_Tree{
    void buildSegTree(vector<int>&arr,vector<int>&segTree,int i,int l,int r){
        if(l==r){
            segTree[i]=arr[r];
            return;
        }
        
        int mid=l+(r-l)/2;
        
        buildSegTree(arr,segTree,2*i+1,l,mid);
        buildSegTree(arr,segTree,2*i+2,mid+1,r);
        
        segTree[i]=segTree[2*i+1]+segTree[2*i+2];
    }
    int solve(vector<int>&segTree,int i,int l,int r,int queryLeft,int queryRight){
        if(l>queryRight || r<queryLeft){
            return 0;
        }
        
        if(l>=queryLeft && r<=queryRight){
            return segTree[i];
        }
        
        int mid=l+(r-l)/2;
        
        return solve(segTree,2*i+1,l,mid,queryLeft,queryRight)+
               solve(segTree,2*i+2,mid+1,r,queryLeft,queryRight);
    }
    public:
    vector<int> querySum(int n,vector<int>arr,int q,vector<int>queries){
        vector<int>segTree(4*n);
        
        buildSegTree(arr,segTree,0,0,n-1);
        
        vector<int>ans;
        
        for(int i=0;i<2*q;i+=2){
            // 1 - Based Indexing
            int left=queries[i]-1;
            int right=queries[i+1]-1;
            
            ans.push_back(solve(segTree,0,0,n-1,left,right));
        }
        
        return ans;
    }
};
int main(){
    // Output: 10 5
    int n=4,q=2;
    vector<int>arr={1,2,3,4},queries={1,4,2,3};
    // Output: 29 78
    int n2=5,q2=2;
    vector<int>arr2={26,30,48,29,8},queries2={4,4,2,3};

    Segment_Tree sol;
    vector<int>ans=sol.querySum(n,arr,q,queries);

    for(int &i:ans) cout<<i<<" ";
    
    return 0;
}