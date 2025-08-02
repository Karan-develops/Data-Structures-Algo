// LC - 2179 - HARD - Count Good Triplets in an Array
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Segment_Tree{
    typedef long long ll;
    vector<ll>segTree;
    void updateSegTree(int i,int l,int r,int updateIdx){
        if(l==r){
            segTree[i]=1;
            return;
        }

        int mid=l+(r-l)/2;

        if(updateIdx<=mid){
            updateSegTree(2*i+1,l,mid,updateIdx);
        } else{
            updateSegTree(2*i+2,mid+1,r,updateIdx);
        }

        segTree[i]=segTree[2*i+1]+segTree[2*i+2];
    }
    long long querySegTree(int i,int l,int r,int queryLeft,int queryRight){
        if(l>queryRight || r<queryLeft){
            return 0;
        }

        if(l>=queryLeft && r<=queryRight){
            return segTree[i];
        }

        int mid=l+(r-l)/2;

        return querySegTree(2*i+1,l,mid,queryLeft,queryRight)+
               querySegTree(2*i+2,mid+1,r,queryLeft,queryRight);
    }
    public:
    long long goodTriplets(vector<int>&nums1,vector<int>&nums2){
        int n=nums1.size();
        unordered_map<int,int>mp;

        for(int i=0;i<n;i++){
            mp[nums2[i]]=i;
        }

        segTree.clear();
        segTree.resize(4*n);
        // Update with first element's mapped index from nums2
        updateSegTree(0,0,n-1,mp[nums1[0]]);

        ll ans=0;

        for(int i=1;i<n;i++){
            int idx=mp[nums1[i]];
            
            ll leftCommonCount=querySegTree(0,0,n-1,0,idx);
            ll leftNotCommonCount=i-leftCommonCount;
            ll elementAfterIdxNum2=(n-1)-idx;
            ll rightCommonCount=elementAfterIdxNum2-leftNotCommonCount;

            ans+=(leftCommonCount*rightCommonCount);

            updateSegTree(0,0,n-1,idx);
        }
        return ans;
    }
};
int main(){
    // Output: 1
    vector<int>nums1={2,0,1,3},nums2={0,1,2,3};
    // Output: 4
    vector<int>nums3={4,0,1,3,2},nums4={4,1,0,2,3};

    Segment_Tree sol;
    cout<<sol.goodTriplets(nums1,nums2)<<endl;
    cout<<sol.goodTriplets(nums3,nums4);
    return 0;
}