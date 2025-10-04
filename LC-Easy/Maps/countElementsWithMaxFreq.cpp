// LC - 3005 - Easy - Count Elements With Maximum Frequency
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int maxFrequencyElements(vector<int>&nums){
    unordered_map<int,int>mp;
    
    for(int &i:nums) mp[i]++;

    int ans=0,maxCount=INT_MIN;

    for(auto &it:mp){
        if(it.second>maxCount){
            ans=it.second;
            maxCount=it.second;
        } else if(it.second==maxCount){
            ans+=it.second;
        }
    }
    return ans;
}
int main(){
    // Output: 4
    vector<int>nums={1,2,2,3,1,4};
    // Output: 5
    vector<int>nums2={1,2,3,4,5};
    cout<<maxFrequencyElements(nums)<<endl;
    cout<<maxFrequencyElements(nums2);
    return 0;
}