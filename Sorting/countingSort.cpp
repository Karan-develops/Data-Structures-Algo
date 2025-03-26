// Sort Array by counting freq of each element
// Preferred to use only on small size arrays
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
vector<int> sortArray(vector<int>& nums) {
    // Counting Sort
    int mini=*min_element(begin(nums),end(nums));
    int maxi=*max_element(begin(nums),end(nums));

    unordered_map<int,int>mp;
    for(auto &i:nums) mp[i]++;
    nums.clear();

    for(int i=mini;i<=maxi;i++){
        while(mp[i]--){
            nums.push_back(i);
        }
    }
    return nums;
}
int main(){
    // Output: [1,2,3,5]
    vector<int>nums={5,2,3,1};
    // Output: [0,0,1,1,2,5]
    vector<int>nums2={5,1,1,2,0,0};
    return 0;
}