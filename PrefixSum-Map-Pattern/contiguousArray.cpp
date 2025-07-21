// LC - 525 - Medium - Contiguous Array
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int findMaxLength(vector<int>&nums){
    int n=nums.size();

    // Element->Idx
    unordered_map<int,int>mp;
    mp[0]=-1;

    int ans=0;
    int prefixSum=0;

    for(int i=0;i<n;i++){
        if(nums[i]==1) prefixSum+=1;
        else prefixSum-=1;

        if(mp.count(prefixSum)){
            ans=max(ans,i-mp[prefixSum]);
        } else{
            mp[prefixSum]=i;
        }
    }
    return ans;
}
int main(){
    // Output: 2
    vector<int>nums={0,1};
    // Output: 2
    vector<int>nums2={0,1,0};
    // Output: 6
    vector<int>nums3={0,1,1,1,1,1,0,0,0};
    cout<<findMaxLength(nums)<<endl;
    cout<<findMaxLength(nums2)<<endl;
    cout<<findMaxLength(nums3);
    return 0;
}