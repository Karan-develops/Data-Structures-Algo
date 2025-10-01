// LC - 2221 - Medium - Find Triangular Sum of an Array
// 2 Approaches
#include<iostream>
#include<vector>
using namespace std;
// Approach 1 - Taking temp vector
int triangularSum(vector<int>&nums){
    while(nums.size()>1){
        vector<int>temp;
        
        for(int i=0;i<nums.size()-1;i++){
            temp.push_back((nums[i]+nums[i+1])%10);
        }
        
        // std::move - avoids copying and is faster and more memory-efficient.
        nums=move(temp);
    }
    return nums[0];
}
// Approach 2 - Constant Space
int triangularSumConstant(vector<int>&nums){
    int n=nums.size();
    
    for(int lastIdx=n-1;lastIdx>=1;lastIdx--){
        for(int i=0;i<lastIdx;i++){
            nums[i]=(nums[i]+nums[i+1])%10;
        }
    }
    return nums[0];
}
int main(){
    // Output: 8
    vector<int>nums={1,2,3,4,5};
    // Output: 5
    vector<int>nums2={5};
    cout<<triangularSum(nums)<<endl;
    cout<<triangularSum(nums2);
    return 0;
}