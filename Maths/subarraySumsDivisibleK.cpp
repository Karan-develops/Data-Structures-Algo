// LC - 974 - Medium - Subarray Sums Divisible by K
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int subarraysDivByK(vector<int>&nums,int k){
    int n=nums.size();
    
    unordered_map<int,int>mp;
    mp[0]=1;
    
    int ans=0;
    int sum=0;
    
    for(int i=0;i<n;i++){
        sum+=nums[i];
        
        int rem=sum%k;
        
        if(rem<0) rem += k;
        
        if(mp.count(rem)){
            ans+=mp[rem];
        }
        
        mp[rem]++;
    }
    
    return ans;
}
int main(){
    // Output: 7
    vector<int>nums={4,5,0,-2,-3,1};
    int k=5;
    // Output: 0
    vector<int>nums2={5};
    int k2=9;
    cout<<subarraysDivByK(nums,k)<<endl;
    cout<<subarraysDivByK(nums2,k2);
    return 0;
}