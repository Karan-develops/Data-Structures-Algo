// LC - 3346 - Medium - Maximum Frequency of an Element After Performing Operations I
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
int maxFrequency(vector<int>&nums,int k,int numOperations){
    int n=nums.size();
    int maxVal=*max_element(begin(nums),end(nums));

    vector<int>diff(maxVal+2,0);
    unordered_map<int,int>mp;

    for(int i=0;i<n;i++){
        mp[nums[i]]++;

        int l=max(nums[i]-k,0);
        int r=min(nums[i]+k,maxVal);

        diff[l]++;
        diff[r+1]--;
    }

    int ans=1;

    for(int target=0;target<=maxVal;target++){
        diff[target]+=(target>0?diff[target-1]:0);

        int targetFreq=mp[target];
        int needConversion=diff[target]-targetFreq;

        int maxPossibleFreq=min(needConversion,numOperations);

        ans=max(ans,targetFreq+maxPossibleFreq);
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