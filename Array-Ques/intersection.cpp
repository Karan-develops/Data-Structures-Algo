// LC - 349 - Easy - Intersection of Two Arrays
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int>ans;
    unordered_set<int>st(begin(nums1),end(nums1));
    unordered_set<int>st2(begin(nums2),end(nums2));

    for(auto &it:st2){
        if(st.find(it)!=st.end()){
            ans.push_back(it);
        }
    }
    return ans;
}
int main(){
    // Output: [2]
    vector<int>nums1={1,2,2,1},nums2={2,2};
    // Output: [9,4]
    vector<int>nums3={4,9,5},nums4={9,4,9,8,4};
    return 0;
}