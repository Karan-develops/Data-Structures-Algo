// LC - 15 - Medium - 3Sum
// nums[i] + nums[j] + nums[k] == 0
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class ThreeSum{
    int n;
    vector<vector<int>>ans;
    void twoSum(vector<int>&nums,int target,int i){
        int j=n-1;
        
        while(i<j){
            int sum=nums[i]+nums[j];
            
            if(sum<target) i++;
            else if(sum>target) j--;
            else{
                ans.push_back({-target,nums[i],nums[j]});
                
                while(i<j && nums[i]==nums[i+1]) i++;
                while(i<j && nums[j]==nums[j-1]) j--;
                
                i++,j--;
            }
        }
    }
    public:
    vector<vector<int>> threeSum(vector<int>&nums){
        n=nums.size();
        if(n<3) return {};

        ans.clear();
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n-2;i++){
            if(i!=0 && nums[i]==nums[i-1]) continue;
            
            twoSum(nums,-nums[i],i+1);
        }

        return ans;
    }
};
int main(){
    // Output: [[-1,-1,2],[-1,0,1]]
    vector<int>nums={-1,0,1,2,-1,-4};
    // Output: []
    vector<int>nums2={0,1,1};
    // Output: [[0,0,0]]
    vector<int>nums3={0,0,0};
    return 0;
}