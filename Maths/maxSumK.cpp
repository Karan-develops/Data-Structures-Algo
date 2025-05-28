// LC - 2656 - Easy - Maximum Sum With Exactly K Elements
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maximizeSum(vector<int>& nums, int k) {
    int maxi=*max_element(begin(nums),end(nums));

    return ((maxi+k-1)*(maxi+k)/2)-((maxi-1)*(maxi)/2);
}
int main(){
    // Output: 18
    vector<int>nums={1,2,3,4,5};
    int k=3;
    // Output: 11
    vector<int>nums2={5,5,5};
    int k2=2;
    cout<<maximizeSum(nums,k)<<endl;
    cout<<maximizeSum(nums2,k2);
    return 0;
}