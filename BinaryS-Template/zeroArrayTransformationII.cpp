// LC - 3356 - Medium - Zero Array Transformation II
// This Solution will Give TLE
// Below is Binary Search Solution
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class TLESolution{
    int N,Q;
    bool checkWithDifferenceArrayTeq(vector<int>&nums,vector<vector<int>>&queries,int k){
        vector<int>diff(N,0);
        for(int i=0;i<=k;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            int x=queries[i][2];

            diff[l]+=x;
            if(r+1<N) diff[r+1]-=x;
        }
        int cummSum=0;
        for(int i=0;i<N;i++){
            cummSum+=diff[i];
            diff[i]=cummSum;
            
            // nums[i] 0 nahi ban paya
            if(nums[i]-diff[i]>0){
                return false;
            }
        }
        return true;
    }
    public:
    int minZeroArray(vector<int>&nums,vector<vector<int>>&queries){
        N=nums.size(),Q=queries.size();
        auto lambda=[](int x){
            return x==0;
        };
        // No query required because all are already zero
        if(all_of(nums.begin(),nums.end(),lambda)) return 0;

        for(int i=0;i<Q;i++){
            if(checkWithDifferenceArrayTeq(nums,queries,i)){
                return i+1;
            }
        }
        return -1;
    }
};
// Binary Search
class BinarySolution{
    int N,Q;
    bool checkWithDifferenceArrayTeq(vector<int>&nums,vector<vector<int>>&queries,int k){
        vector<int>diff(N,0);
        for(int i=0;i<=k;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            int x=queries[i][2];

            diff[l]+=x;
            if(r+1<N) diff[r+1]-=x;
        }
        int cummSum=0;
        for(int i=0;i<N;i++){
            cummSum+=diff[i];
            diff[i]=cummSum;
            
            // nums[i] 0 nahi ban paya
            if(nums[i]-diff[i]>0){
                return false;
            }
        }
        return true;
    }
    public:
    int minZeroArray(vector<int>&nums,vector<vector<int>>&queries){
        N=nums.size(),Q=queries.size();
        auto lambda=[](int x){
            return x==0;
        };
        // No query required because all are already zero
        if(all_of(nums.begin(),nums.end(),lambda)) return 0;

        int l=0;
        int r=Q-1;
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(checkWithDifferenceArrayTeq(nums,queries,mid)){
                ans=mid+1;
                r=mid-1;
            } else{
                l=mid+1;
            }
        }
        return ans;
    }
};
int main(){
    // OP - 2
    vector<int>nums1={2,0,2};
    vector<vector<int>>queries1={{0,2,1},{0,2,1},{1,1,3}};
    // OP - -1
    vector<int>nums2={4,3,2,1};
    vector<vector<int>>queries2={{1,3,2},{0,2,1}};
    BinarySolution sol;
    cout<<sol.minZeroArray(nums1,queries1)<<endl;
    cout<<sol.minZeroArray(nums2,queries2);
    return 0;
}