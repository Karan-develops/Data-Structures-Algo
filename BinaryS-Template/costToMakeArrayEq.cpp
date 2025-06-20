// LC - 2448 - HARD - Minimum Cost to Make Array Equal
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class BinarySearch{
    typedef long long ll;
    ll getCost(vector<int>&nums,vector<int>&cost,int mid){
        ll total_cost=0;

        for(int i=0;i<nums.size();i++){
            total_cost+=(ll) abs(nums[i]-mid)*cost[i];
        }
        return total_cost;
    }
    public:
    long long minCost(vector<int>&nums,vector<int>&cost){
        ll ans=INT_MAX;

        int l=*min_element(begin(nums),end(nums));
        int r=*max_element(begin(nums),end(nums));

        while(l<=r){
            int mid=l+(r-l)/2;

            ll cost1=getCost(nums,cost,mid);
            ll cost2=getCost(nums,cost,mid+1);
            ans=min(cost1,cost2);

            if(cost1<cost2) r=mid-1;
            else l=mid+1;
        }
        return ans==INT_MAX?0:ans;
    }
};
int main(){
    // Output: 8
    vector<int>nums={1,3,5,2},cost={2,3,1,14};
    // Output: 0
    vector<int>nums2={2,2,2,2,2},cost2={4,2,8,1,3};

    BinarySearch sol;
    cout<<sol.minCost(nums,cost)<<endl;
    cout<<sol.minCost(nums2,cost2);
    return 0;
}