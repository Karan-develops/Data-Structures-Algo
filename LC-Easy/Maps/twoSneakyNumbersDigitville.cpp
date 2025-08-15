// LC - 3289 - The Two Sneaky Numbers of Digitville
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> getSneakyNumbers(vector<int>& nums) {
    int n=nums.size();
    vector<int>ans;
    unordered_map<int,int>mp;

    for(int &i:nums){
        mp[i]++;
        if(mp[i]>1) ans.push_back(i);
    }
    return ans;
}
int main(){
    // Output: [0,1]
    vector<int>nums={0,1,1,0};
    // Output: [2,3]
    vector<int>nums2={0,3,2,1,3,2};
    // Output: [4,5]
    vector<int>nums3={7,1,5,4,3,4,6,0,9,5,8,2};
    return 0;
}