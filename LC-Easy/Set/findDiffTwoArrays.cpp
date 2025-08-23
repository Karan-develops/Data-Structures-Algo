// LC - 2215 - Easy - Find the Difference of Two Arrays
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
vector<vector<int>> findDifference(vector<int>&nums1,vector<int>&nums2){
    vector<vector<int>>ans(2);
    unordered_set<int>s1(begin(nums1),end(nums1));
    unordered_set<int>s2(begin(nums2),end(nums2));

    for(auto &i:s1){
        if(s2.find(i)==s2.end()) ans[0].push_back(i);
    }
    for(auto &i:s2){
        if(s1.find(i)==s1.end()) ans[1].push_back(i);
    }
    return ans;
}
int main(){
    // Output: [[1,3],[4,6]]
    vector<int>nums1={1,2,3},nums2={2,4,6};
    // Output: [[3],[]]
    vector<int>nums3={1,2,3,3},nums4={1,1,2,2};
    return 0;
}