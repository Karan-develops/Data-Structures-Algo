// LC - 3375 - Easy - Minimum Operations to Make Array Values Equal to K
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int minOperations(vector<int>&nums,int k){
    unordered_set<int>st;
    for(int &i:nums){
        if(i<k) return -1;
        else if(i>k) st.insert(i);
    }
    return st.size();
}
int main(){
    // Output: 2
    vector<int>nums={5,2,5,4,5};
    int k=2;
    // Output: -1
    vector<int>nums2={2,1,2};
    int k2=2;
    // Output: 4
    vector<int>nums3={9,7,5,3};
    int k3=1;
    cout<<minOperations(nums,k)<<endl;
    cout<<minOperations(nums2,k2)<<endl;
    cout<<minOperations(nums3,k3);
    return 0;
}