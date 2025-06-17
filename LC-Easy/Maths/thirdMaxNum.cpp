// LC - 414 - Easy - Third Maximum Number
#include<iostream>
#include<vector>
using namespace std;
int thirdMax(vector<int>&nums){
    long l1=LONG_MIN,l2=LONG_MIN,l3=LONG_MIN;

    for(int &i:nums){
        if(i==l1 || i==l2 || i==l3) continue;

        if(i>l1){
            l3=l2;
            l2=l1;
            l1=i;
        } else if(i>l2){
            l3=l2;
            l2=i;
        } else if(i>l3){
            l3=i;
        }
    }

    return l3==LONG_MIN?l1:l3;
}
int main(){
    // Output: 1
    vector<int>nums={3,2,1};
    // Output: 2
    vector<int>nums2={1,2};
    // Output: 1
    vector<int>nums3={2,2,3,1};
    cout<<thirdMax(nums)<<endl;
    cout<<thirdMax(nums2)<<endl;
    cout<<thirdMax(nums3);
    return 0;
}