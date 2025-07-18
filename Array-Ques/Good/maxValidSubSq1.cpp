// LC - 3201 - Medium - Find the Maximum Length of Valid Subsequence I
#include<iostream>
#include<vector>
using namespace std;
int maximumLength(vector<int>&nums){
    int n=nums.size();
    int even=0,odd=0;

    for(int &i:nums){
        if(i & 1) odd++;
        else even++;
    }

    int ans=1;
    int prevParity=nums[0]&1;

    for(int i=1;i<n;i++){
        int currParity=nums[i]&1;

        if(currParity!=prevParity){
            prevParity=currParity;
            ans++;
        }
    }

    return max(odd,max(even,ans)); 
}
int main(){
    // Output: 4
    vector<int>nums={1,2,3,4};
    // Output: 6
    vector<int>nums2={1,2,1,1,2,1,2};
    // Output: 2
    vector<int>nums3={1,3};
    cout<<maximumLength(nums)<<endl;
    cout<<maximumLength(nums2)<<endl;
    cout<<maximumLength(nums3);
    return 0;
}