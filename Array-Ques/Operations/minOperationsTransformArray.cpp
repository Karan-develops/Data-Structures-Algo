// LC - 3724 - Medium - Minimum Operations to Transform Array
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Array{
    typedef long long ll;
    public:
    long long minOperations(vector<int>&nums1,vector<int>&nums2){
        int n=nums1.size();

        ll base=0;

        for(int i=0;i<n;i++){
            base+=llabs((ll)nums1[i]-nums2[i]);
        }

        ll ans=LLONG_MAX;
        
        for(int i=0;i<n;i++){
            ll a=nums1[i];
            ll b=nums2[i];
            ll c=nums2.back();

            ll maxVal=max({a,b,c});
            ll minVal=min({a,b,c});

            ll x=(maxVal-minVal)-llabs(a-b);
            
            ans=min(ans,x);
        }

        return 1+base+ans;
    }
};
int main(){
    // Output: 4
    vector<int>nums1={2,8},nums2={1,7,3};
    // Output: 4
    vector<int>nums3={1,3,6},nums4={2,4,5,3};
    // Output: 3
    vector<int>nums5={2},nums6={3,4};

    Array sol;
    cout<<sol.minOperations(nums1,nums2)<<endl;
    cout<<sol.minOperations(nums3,nums4)<<endl;
    cout<<sol.minOperations(nums5,nums6);
    return 0;
}