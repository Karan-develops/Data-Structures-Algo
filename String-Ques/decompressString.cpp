// LC - 1313 - Easy - Decompress Run-Length Encoded List
#include<iostream>
#include<vector>
using namespace std;
vector<int> decompressRLElist(vector<int>& nums) {
    int n=nums.size();
    vector<int>ans;
    for(int i=0;i<n;i+=2){
        int count=nums[i],num=nums[i+1];
        ans.insert(ans.end(),count,num);
    }
    return ans;
}
int main(){
    // Output: [2,4,4,4]
    vector<int>nums={1,2,3,4};
    // Output: [1,3,3]
    vector<int>nums2={1,1,2,3};
    return 0;
}