// LC - 2845 - Medium - Count of Interesting Subarrays
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
long long countInterestingSubarrays(vector<int>&nums,int modulo,int k){
    long long ans=0,count=0;
    unordered_map<int,long long>mp;
    mp[0]=1;
    for(int &i:nums){
        if(i%modulo==k) count++;

        int rem=(count-k+modulo)%modulo;
        ans+=mp[rem];
        
        mp[count%modulo]++;
    }
    return ans;
}
int main(){
    // Output: 3
    vector<int>nums={3,2,4};
    int modulo=2,k=1;
    // Output: 2
    vector<int>nums2={3,1,9,6};
    int modulo2=3,k2=0;
    cout<<countInterestingSubarrays(nums,modulo,k)<<endl;
    cout<<countInterestingSubarrays(nums2,modulo2,k2);
    return 0;
}