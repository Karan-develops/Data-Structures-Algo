// LC - 137 - Medium - Single Number II
#include<iostream>
#include<vector>
using namespace std;
int singleNumber(vector<int>&nums){
    int ans=0;
    for(int i=0;i<32;i++){
        int temp=(1<<i);
        int countOne=0,countZero=0;
        
        for(int &num:nums){
            if((num&temp)==0) countZero++;
            else countOne++;
        }
        if(countOne%3==1) ans=(ans|temp);
    }
    return ans;
}
int main(){
    // Output: 3
    vector<int>nums={2,2,3,2};
    // Output: 99
    vector<int>nums2={0,1,0,1,0,1,99};
    cout<<singleNumber(nums)<<endl;
    cout<<singleNumber(nums2);
    return 0;
}