// LC - 1546 - Medium - Maximum Number of Non-Overlapping Subarrays With Sum Equals Target
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int maxNonOverlapping(vector<int>& nums, int target) {
    int ans=0;

    unordered_set<int>st;
    int prefixSum=0;
    st.insert(0);

    for(int &i:nums){
        prefixSum+=i;
        if(st.count(prefixSum-target)){
            ans++;
            st.clear();
            st.insert(0);
            prefixSum=0;
        } else{
            st.insert(prefixSum); 
        }
    }
    return ans;
}
int main(){
    // Output: 2
    vector<int>nums={1,1,1,1,1};
    int target=2;
    // Output: 2
    vector<int>nums2={-1,3,5,1,4,2,-9};
    int target2=6;
    cout<<maxNonOverlapping(nums,target)<<endl;
    cout<<maxNonOverlapping(nums2,target2);
    return 0;
}