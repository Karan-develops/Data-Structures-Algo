// LC - 2918 - Medium - Minimum Equal Sum of Two Arrays After Replacing Zeros
#include<iostream>
#include<vector>
using namespace std;
long long minSum(vector<int>& nums1, vector<int>& nums2) {
    int m=nums1.size(),n=nums2.size();
    long long sum1=0,sum2=0;
    long long zero1=0,zero2=0;

    for(int &i:nums1){
        sum1+=i;
        if(i==0){
            sum1+=1;
            zero1+=1;
        }
    }
    for(int &i:nums2){
        sum2+=i;
        if(i==0){
            sum2+=1;
            zero2+=1;
        }
    }
    if((sum1<sum2 && zero1==0) || (sum2<sum1 && zero2==0)){
        return -1;
    }
    return max(sum1,sum2);
}
int main(){
    // Output: 12
    vector<int>nums1={3,2,0,1,0},nums2={6,5,0};
    // Output: -1
    vector<int>nums3={2,0,2,0},nums4={1,4};
    cout<<minSum(nums1,nums2)<<endl;
    cout<<minSum(nums3,nums4);
    return 0;
}