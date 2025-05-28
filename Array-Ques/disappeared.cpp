// LC - 448 - Easy - Find All Numbers Disappeared in an Array
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int>ans;
    unordered_map<int,int>mp;

    for(int &i:nums) mp[i]++;

    for(int i=1;i<=nums.size();i++){
        if(!mp.count(i)) ans.push_back(i);
    }
    return ans;
}
int main(){
    // Output: [5,6]
    vector<int>nums={4,3,2,7,8,2,3,1};
    // Output: [2]
    vector<int>nums2={1,1};
    return 0;
}