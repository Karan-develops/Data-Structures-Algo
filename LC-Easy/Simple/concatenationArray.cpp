// LC - 1929 - Easy - Concatenation of Array
#include<iostream>
#include<vector>
using namespace std;
vector<int> getConcatenation(vector<int>&nums){
    vector<int>ans(begin(nums),end(nums));

    ans.insert(end(ans),begin(nums),end(nums));

    return ans;
}
int main(){
    // Output: [1,2,1,1,2,1]
    vector<int>nums={1,2,1};
    // Output: [1,3,2,1,1,3,2,1]
    vector<int>nums2={1,3,2,1};
    return 0;
}