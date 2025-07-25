// LC - 1413 - Easy - Minimum Value to Get Positive Step by Step Sum
#include<iostream>
#include<vector>
using namespace std;
int minStartValue(vector<int>&nums){
    int sum=0,minSum=0;

    for(int &i:nums){
        sum+=i;
        minSum=min(minSum,sum);
    }

    return 1-minSum;
}
int main(){
    // Output: 5
    vector<int>nums={-3,2,-3,4,2};
    // Output: 1
    vector<int>nums2={1,2};
    // Output: 5
    vector<int>nums3={1,-2,-3};
    cout<<minStartValue(nums)<<endl;
    cout<<minStartValue(nums2)<<endl;
    cout<<minStartValue(nums3);
    return 0;
}