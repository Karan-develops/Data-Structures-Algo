// LC - 3736 - Easy - Minimum Moves to Equal Array Elements III
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int minMoves(vector<int>&nums){
    int maxE=*max_element(begin(nums),end(nums));

    int ans=0;

    for(int &i:nums) ans+=abs(maxE-i);

    return ans;
}
int main(){
    // Output: 3
    vector<int>nums={2,1,3};
    // Output: 2
    vector<int>nums2={4,4,5};
    cout<<minMoves(nums)<<endl;
    cout<<minMoves(nums2);
    return 0;
}