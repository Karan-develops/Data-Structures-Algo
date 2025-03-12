// LC - 2529 - Easy
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// O(n)
int maximumCount(vector<int>&nums){
    int pos=0,neg=0;
    for(auto &i:nums){
        if(i>0) pos++;
        else if(i<0) neg++;
    }
    return pos>neg?pos:neg;
}
// Using STL - O(n)
int maximumCount2(vector<int>&nums){
    auto posLambda=[](int num){
        return num>0;
    };
    auto negLambda=[](int num){
        return num<0;
    };
    int pos=count_if(nums.begin(),nums.end(),posLambda);
    int neg=count_if(nums.begin(),nums.end(),negLambda);
    return max(pos,neg);
}
// Binary Search - O(logn)
int maximumCount3(vector<int>&nums){
    int n=nums.size();
    int indexOfFirstPositiveNum=lower_bound(nums.begin(),nums.end(),1)-nums.begin();
    int indexOfFirstNegativeNum=lower_bound(nums.begin(),nums.end(),0)-nums.begin();
    return max(n-indexOfFirstPositiveNum,indexOfFirstNegativeNum);
}
int main(){
    // OP - 3
    vector<int>nums1={-2,-1,-1,1,2,3};
    // OP - 3
    vector<int>nums2={-3,-2,-1,0,0,1,2};
    // OP - 4
    vector<int>nums3={5,20,66,1314};
    cout<<maximumCount3(nums1)<<endl;
    cout<<maximumCount3(nums2)<<endl;
    cout<<maximumCount3(nums3)<<endl;
    return 0;
}