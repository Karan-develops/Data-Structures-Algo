// LC - 334 - Medium - Increasing Triplet Subsequence
#include<iostream>
#include<vector>
using namespace std;
bool increasingTriplet(vector<int>& nums) {
    int first=INT_MAX;
    int second=INT_MAX;
    for(int &i:nums){
        if(i<=first) first=i;
        else if(i<=second) second=i;
        else return true;
    }
    return false;
}
int main(){
    // Output: true
    vector<int>nums={1,2,3,4,5};
    // Output: false
    vector<int>nums2={5,4,3,2,1};
    // Output: true
    vector<int>nums3={2,1,5,0,4,6};
    cout<<increasingTriplet(nums)<<endl;
    cout<<increasingTriplet(nums2)<<endl;
    cout<<increasingTriplet(nums3);
    return 0;
}