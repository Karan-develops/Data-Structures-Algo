// LC - 3688 - Easy - Bitwise OR of Even Numbers in an Array
#include<iostream>
#include<vector>
using namespace std;
int evenNumberBitwiseORs(vector<int>&nums){
    int ans=0;

    for(int &i:nums){
        if(!(i&1)) ans|=i;
    }

    return ans;
}
int main(){
    // Output: 6
    vector<int>nums={1,2,3,4,5,6};
    // Output: 0
    vector<int>nums2={7,9,11};
    // Output: 24
    vector<int>nums3={1,8,16};
    cout<<evenNumberBitwiseORs(nums)<<endl;
    cout<<evenNumberBitwiseORs(nums2)<<endl;
    cout<<evenNumberBitwiseORs(nums3);
    return 0;
}