// LC - 3681 - HARD - Maximum XOR of Subsequences
#include<iostream>
#include<vector>
using namespace std;
int maxXorSubsequences(vector<int>&nums){
    vector<int>temp;

    for(int &i:nums){
        for(int &j:temp){
            i=min(i,i^j);
        }
        if(i) temp.push_back(i);
    }

    int ans=0;
    for(int &i:temp){
        ans=max(ans,ans^i);
    }

    return ans;
}
int main(){
    // Output: 3
    vector<int>nums={1,2,3};
    // Output: 7
    vector<int>nums2={5,2};
    cout<<maxXorSubsequences(nums)<<endl;
    cout<<maxXorSubsequences(nums2);
    return 0;
}