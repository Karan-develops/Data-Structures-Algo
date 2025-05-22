// Number of Swaps required to make numsay strictly increasing
// 2 Methods
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
// Approach 1 - Using Map
int swapCount(vector<int>&nums){
    int swaps=0;

    vector<int>sortedArr(begin(nums),end(nums));
    sort(begin(sortedArr),end(sortedArr));

    unordered_map<int,int>mp;
    for(int i=0;i<nums.size();i++){
        mp[nums[i]]=i;
    }

    for(int i=0;i<nums.size();i++){
        // No swap required
        if(nums[i]==sortedArr[i]) continue;

        int currIdx=mp[sortedArr[i]];
        mp[nums[i]]=currIdx;
        mp[nums[currIdx]]=i;
        swap(nums[i],nums[currIdx]);
        swaps++;
    }
    return swaps;
}
// Approach 2 - Without Map
int swapCount2(vector<int>&nums){
    int n=nums.size();
    vector<pair<int,int>>sortedArr(n);
    
    for(int i=0;i<n;i++){
        sortedArr[i]={nums[i],i};
    }

    // Sort by numsay values
    sort(sortedArr.begin(),sortedArr.end());

    vector<bool> visited(n,false);
    int swaps=0;

    for(int i=0;i<n;i++){
        // Already visited or already in the correct place
        if(visited[i] || sortedArr[i].second==i) continue;

        int cycle_size=0;
        int j=i;

        // Traverse the cycle
        while (!visited[j]){
            visited[j]=true;
            j=sortedArr[j].second;
            cycle_size++;
        }

        if(cycle_size>1) swaps+=(cycle_size-1);
    }
    return swaps;
}
int main(){
    // 2
    vector<int>nums={7,6,5,4};
    // 0
    vector<int>nums2={1,2,3};
    // 1
    vector<int>nums3={3,2,1};
    cout<<swapCount(nums)<<endl;
    cout<<swapCount(nums2)<<endl;
    cout<<swapCount(nums3);
    return 0;
}