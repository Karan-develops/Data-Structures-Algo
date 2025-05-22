// LC - 268 - Easy - Missing Number
// 4 Approaches
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Approach 1 - Brute Force
int missingNumber(vector<int>&nums){
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size();i++){
        if(i!=nums[i]) return i;
    }
    return nums.size();
}
// Approach 2 - Bit Magic
int missingNumber2(vector<int>&nums){
    int n=nums.size();
    int ans=nums.size();
    
    for(int i=0;i<n;i++){
        ans^=i;
        ans^=nums[i];
    }
    return ans;
}
// Approach 3 - Maths
int missingNumber3(vector<int>&nums){
    int n=nums.size();
    int sum=n*(n+1)/2;
    for(int i=0;i<n;i++){
        sum-=nums[i];
    }
    return sum;
}
// Approach 4 - Binary Search
int missingNumber4(vector<int>&nums){
    int n=nums.size();
    sort(nums.begin(),nums.end());
    int l=0;
    int r=n-1;
    int ans=n;
    
    while(l<=r){
        int mid=l+(r-l)/2;
        if(nums[mid]>mid){
            ans=mid;
            r=mid-1;
        } else{
            l=mid+1;
        }
    }
    return ans;   
}
int main(){
    // Output: 2
    vector<int>nums={3,0,1};
    // Output: 2
    vector<int>nums2={0,1};
    // Output: 8
    vector<int>nums3={9,6,4,2,3,5,7,0,1};
    cout<<missingNumber(nums)<<endl;
    cout<<missingNumber(nums2)<<endl;
    cout<<missingNumber(nums3);
    return 0;
}