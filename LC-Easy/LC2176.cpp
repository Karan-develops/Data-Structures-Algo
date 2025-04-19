// LC - 2176 - Easy - Count Equal and Divisible Pairs in an Array
#include<iostream>
#include<vector>
using namespace std;
int countPairs(vector<int>& nums, int k) {
    int n=nums.size();
    int ans=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if((i*j)%k==0 && nums[i]==nums[j]){
                ans++;
            }
        }
    }
    return ans;
}
int main(){
    // Output: 4
    vector<int>nums={3,1,2,2,2,1,3};
    int k=2;
    // Output: 0
    vector<int>nums2={1,2,3,4};
    int k2=1;
    cout<<countPairs(nums,k)<<endl;
    cout<<countPairs(nums2,k2);
    return 0;
}