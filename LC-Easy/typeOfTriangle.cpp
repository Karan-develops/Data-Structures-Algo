// LC - 3024 - Easy - Type of Triangle
#include<iostream>
#include<vector>
using namespace std;
string triangleType(vector<int>& nums) {
    bool valid=(nums[0]+nums[1]>nums[2])&&
                (nums[0]+nums[2]>nums[1])&&
                (nums[1]+nums[2]>nums[0]);

    if(!valid) return "none";

    if(nums[0]==nums[1] && nums[1]==nums[2]){
        return "equilateral";
    } else if(nums[0]!=nums[1] && nums[0]!=nums[2] && nums[1]!=nums[2]){
        return "scalene";
    }
    return "isosceles";
}
int main(){
    // Output: "equilateral"
    vector<int>nums={3,3,3};
    // Output: "scalene"
    vector<int>nums2={3,4,5};
    cout<<triangleType(nums)<<endl;
    cout<<triangleType(nums2);
    return 0;
}