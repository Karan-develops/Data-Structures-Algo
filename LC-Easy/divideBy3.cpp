// LC - 3190 - Easy - Find Minimum Operations to Make All Elements Divisible by Three
#include<iostream>
#include<vector>
using namespace std;
int minimumOperations(vector<int>& nums) {
    int ans=0;
    for(int &i:nums){
        if(i%3!=0) ans++;
    }
    return ans;
}
int main(){
    // Output: 3
    vector<int>nums={1,2,3,4};
    // Output: 0
    vector<int>nums2={3,6,9};
    cout<<minimumOperations(nums)<<endl;
    cout<<minimumOperations(nums2);
    return 0;
}