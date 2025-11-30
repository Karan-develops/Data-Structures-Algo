// LC - 1018 - Easy - Binary Prefix Divisible By 5
#include<iostream>
#include<vector>
using namespace std;
vector<bool> prefixesDivBy5(vector<int>&nums){
    int n=nums.size();
    vector<bool>ans(n);

    int rem=0;
    
    for(int i=0;i<n;i++){
        rem=(rem*2+nums[i])%5;

        ans[i]=(rem==0);
    }

    return ans;
}
int main(){
    // Output: [true,false,false]
    vector<int>nums={0,1,1};
    // Output: [false,false,false]
    vector<int>nums2={1,1,1};
    return 0;
}