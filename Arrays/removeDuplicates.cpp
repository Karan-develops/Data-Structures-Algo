// LC - 26 - Easy
// Remove in-place
#include<iostream>
#include<vector>
using namespace std;
int removeDuplicates(vector<int>&nums){
    int n=nums.size();
    int j=1;
    for(int i=1;i<n;i++){
        if(nums[i]!=nums[i-1]){
            nums[j++]=nums[i];
        }
    }
    return j;
}
int main(){
    vector<int>nums={1,1,2};
    vector<int>nums2={0,0,1,1,1,2,2,3,3,4};
    // [1,2,_]
    // OP - 2
    cout<<removeDuplicates(nums)<<endl;
    // [0,1,2,3,4,_,_,_,_,_]
    // OP - 5
    cout<<removeDuplicates(nums2);
    return 0;
}