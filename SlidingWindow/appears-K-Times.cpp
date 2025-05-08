// LC - 2962 - Medium - Count Subarrays Where Max Element Appears at Least K Times
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long countSubarrays(vector<int>&nums,int k){
    int maxE=*max_element(begin(nums),end(nums));

    int n=nums.size();
    long long ans=0;
    int countMax=0;

    int i=0,j=0;
    while(j<n){
        if(nums[j]==maxE) countMax++;

        while(countMax>=k){
            ans+=n-j;
            if(nums[i]==maxE) countMax--;
            i++;
        }
        j++;
    }
    return ans;
}
int main(){
    // Output: 6
    vector<int>nums={1,3,2,3,3};
    int k=2;
    // Output: 0
    vector<int>nums2={1,4,2,1};
    int k2=3;
    cout<<countSubarrays(nums,k)<<endl;
    cout<<countSubarrays(nums2,k2);
    return 0;
}