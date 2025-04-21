// LC - 2179 - HARD - Count Good Triplets in an Array
#include<iostream>
#include<vector>
using namespace std;
long long goodTriplets(vector<int>&nums1,vector<int>&nums2){
    
}
int main(){
    // Output: 1
    vector<int>nums1={2,0,1,3},nums2={0,1,2,3};
    // Output: 4
    vector<int>nums3={4,0,1,3,2},nums4={4,1,0,2,3};
    cout<<goodTriplets(nums1,nums2)<<endl;
    cout<<goodTriplets(nums3,nums4);
    return 0;
}