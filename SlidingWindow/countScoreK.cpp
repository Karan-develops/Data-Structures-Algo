// LC - 2302 - HARD - Count Subarrays With Score Less Than K
#include<iostream>
#include<vector>
using namespace std;
long long countSubarrays(vector<int>& nums, long long k) {
    int n=nums.size();
    long long ans=0;
    long long sum=0;
    
    int i=0,j=0;
    while(j<n){
        sum+=nums[j];

        while(i<=j && sum*(j-i+1)>=k){
            sum-=nums[i];
            i++;
        }

        ans+=(j-i+1);
        j++;
    }
    return ans;
}
int main(){
    // Output: 6
    vector<int>nums={2,1,4,3,5};
    int k=10;
    // Output: 5
    vector<int>nums2={1,1,1};
    int k2=5;
    cout<<countSubarrays(nums,k)<<endl;
    cout<<countSubarrays(nums2,k2);
    return 0;
}