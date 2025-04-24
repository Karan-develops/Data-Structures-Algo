// LC - 189 - Medium - Rotate Array
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void rotate(vector<int>&nums,int k){
    int n=nums.size();
    k%=n;
    reverse(nums.begin(),nums.end());
    reverse(nums.begin(),nums.begin()+k);
    reverse(nums.begin()+k,nums.end());
}
int main(){
    // Output: [5,6,7,1,2,3,4]
    vector<int>nums={1,2,3,4,5,6,7};
    int k=3;
    // Output: [3,99,-1,-100]
    vector<int>nums2={-1,-100,3,99};
    int k2=2;
    return 0;
}