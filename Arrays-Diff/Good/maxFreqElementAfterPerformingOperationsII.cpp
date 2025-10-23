// LC - 3347 - HARD - Maximum Frequency of an Element After Performing Operations II
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
using namespace std;
int maxFrequency(vector<int>&nums,int k,int numOperations){
    int n=nums.size();
    int maxVal=*max_element(begin(nums),end(nums))+k;

    map<int,int>diff;
    unordered_map<int,int>mp;

    for(int i=0;i<n;i++){
        mp[nums[i]]++;

        int l=max(nums[i]-k,0);
        int r=min(nums[i]+k,maxVal);

        diff[l]++;
        diff[r+1]--;

        // nums[i] can also be an answer
        diff[nums[i]]+=0;
    }

    int ans=1;
    int cumSum=0;

    for(auto it=diff.begin();it!=diff.end();it++){
        int target=it->first;
        it->second+=cumSum;

        int targetFreq=mp[target];
        int needConversion=diff[target]-targetFreq;

        int maxPossibleFreq=min(needConversion,numOperations);

        ans=max(ans,targetFreq+maxPossibleFreq);

        cumSum=it->second;
    }
    return ans;
}
int main(){
    // Output: 2
    vector<int>nums={1,4,5};
    int k=1,numOperations=2;
    // Output: 2
    vector<int>nums2={5,11,20,20};
    int k2=5,numOperations2=1;
    cout<<maxFrequency(nums,k,numOperations)<<endl;
    cout<<maxFrequency(nums2,k2,numOperations2);
    return 0;
}