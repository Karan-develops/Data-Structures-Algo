// LC - 229 - Medium - Majority Element II
// 2 Approaches - Map - Boyer Moore Algo
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> majorityElement(vector<int>&nums){
    int n=nums.size();
    unordered_map<int,int>mp;
    for(int &i:nums) mp[i]++;

    vector<int>ans;
    for(auto it:mp){
        if(it.second*3>n) ans.push_back(it.first);
    }
    return ans;
}
vector<int> majorityElement2(vector<int>&nums){
    int n=nums.size();
    int ans1=-1,ans2=-1;
    int count1=0,count2=0;
    for(int i=0;i<n;i++){
        if(nums[i]==ans1) count1++;
        else if(nums[i]==ans2) count2++;
        else if(count1==0){
            ans1=nums[i];
            count1++;
        } else if(count2==0){
            ans2=nums[i];
            count2++;
        }
    }
    // Verification
    vector<int>ans;
    int freq1=0,freq2=0;
    for(int i=0;i<n;i++){
        if(nums[i]==ans1) freq1++;
        else if(nums[i]==ans2) freq2++;
    }
    if(freq1*3>n) ans.push_back(ans1);
    if(freq2*3>n) ans.push_back(ans2);
    return ans;
}
int main(){
    // Output: [3]
    vector<int>nums={3,2,3};
    // Output: [1]
    vector<int>nums2={1};
    // Output: [1,2]
    vector<int>nums3={1,2};
    vector<int>ans=majorityElement2(nums);
    vector<int>ans2=majorityElement2(nums2);
    vector<int>ans3=majorityElement2(nums3);
    for(int &i:ans) cout<<i<<" ";
    cout<<endl;
    for(int &i:ans2) cout<<i<<" ";
    cout<<endl;
    for(int &i:ans3) cout<<i<<" ";
    return 0;
}