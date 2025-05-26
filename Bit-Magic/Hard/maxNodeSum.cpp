// LC - 3068 - HARD - Find the Maximum Sum of Node Values
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
ll maximumValueSum(vector<int>&nums,int k,vector<vector<int>>&edges){
    ll ans=0;
    int count=0;
    int minNuksaan=INT_MAX;

    for(ll i:nums){
        if((i^k)>i){
            count++;
            ans+=i^k;
        } else{
            ans+=i;
        }
        minNuksaan=min((ll)minNuksaan,abs(i-(i^k)));
    }
    if(count%2==0) return ans;
    
    return ans-minNuksaan;
}
int main(){
    // Output: 6
    vector<int>nums={1,2,1};
    int k=3;
    vector<vector<int>>edges={{0,1},{0,2}};
    // Output: 9
    vector<int>nums2={2,3};
    int k2=7;
    vector<vector<int>>edges2={{0,1}};
    // Output: 42
    vector<int>nums3={7,7,7,7,7,7};
    int k3=3;
    vector<vector<int>>edges3={{0,1},{0,2},{0,3},{0,4},{0,5}};
    cout<<maximumValueSum(nums,k,edges)<<endl;
    cout<<maximumValueSum(nums2,k2,edges2)<<endl;
    cout<<maximumValueSum(nums3,k3,edges3);
    return 0;
}