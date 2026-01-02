// LC - 961 - Easy - N-Repeated Element in Size 2N Array
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int repeatedNTimes(vector<int>&nums){
    unordered_set<int>st;
    
    for(int &i:nums){
        if(st.count(i)) return i;
        
        st.insert(i);
    }
    
    return -1;
}
int main(){
    // Output: 3
    vector<int>nums={1,2,3,3};
    // Output: 2
    vector<int>nums2={2,1,2,5,3,2};
    // Output: 5
    vector<int>nums3={5,1,5,2,5,3,5,4};
    cout<<repeatedNTimes(nums)<<endl;
    cout<<repeatedNTimes(nums2)<<endl;
    cout<<repeatedNTimes(nums3);
    return 0;
}