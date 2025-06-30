// LC - 2148 - Easy - Count Elements With Strictly Smaller and Greater Elements
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int countElements(vector<int>&nums){
    int minE=*min_element(begin(nums),end(nums));
    int maxE=*max_element(begin(nums),end(nums));

    int ans=0;
    for(int &i:nums){
        if(i>minE && i<maxE) ans++;
    }
    return ans;
}
int main(){
    // Output: 2
    vector<int>nums={11,7,2,15};
    // Output: 2
    vector<int>nums2={-3,3,3,90};
    cout<<countElements(nums)<<endl;
    cout<<countElements(nums2);
    return 0;
}