// LC - 75 - Medium - Sort Colors
#include<iostream>
#include<vector>
using namespace std;
void sortColors(vector<int>& nums) {
    int i=0,j=0,k=nums.size()-1;
    while(j<=k){
        if(nums[j]==2) swap(nums[j],nums[k--]);
        else if(nums[j]==0) swap(nums[i++],nums[j++]);
        else j++; // j==1
    }
}
int main(){
    // Output: [0,0,1,1,2,2]
    vector<int>nums={2,0,2,1,1,0};
    // Output: [0,1,2]
    vector<int>nums2={2,0,1};
    return 0;
}