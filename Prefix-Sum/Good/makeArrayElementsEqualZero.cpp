// LC - 3354 - Easy - Make Array Elements Equal to Zero
// 2 Approaches
#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
// Approach 1 - Brute Force
class BruteForce{
    bool isValid(vector<int>&nums,int count,int i,int direction){
        vector<int>temp=nums;
        int idx=i;

        while(count>0 && idx>=0 && idx<nums.size()){
            if(temp[idx]>0){
                temp[idx]--;
                direction*=-1;
                
                if(temp[idx]==0){
                    count--;
                }
            }
            idx+=direction;
        }

        return count==0; // all must become 0
    }
    public:
    int countValidSelections(vector<int>&nums){
        int n=nums.size();
        int ans=0;
        int count=0; // count of nums[i]!=0

        for(int i=0;i<n;i++){
            if(nums[i]!=0) count++;
        }

        for(int i=0;i<n;i++){
            if(nums[i]==0){
                if(isValid(nums,count,i,-1)){
                    ans++;
                }
                if(isValid(nums,count,i,1)){
                    ans++;
                }
            }
        }
        return ans;
    }
};
// Approach 2 - Prefix Sum
int countValidSelections(vector<int>&nums){
    int ans=0;
    int currSum=0;
    int totalSum=accumulate(begin(nums),end(nums),0);
    
    for(int &i:nums){
        currSum+=i;
        totalSum-=i;
        
        if(i!=0) continue;

        if(currSum==totalSum) ans+=2;

        if(abs(currSum-totalSum)==1) ans++;
    }
    return ans;
}
int main(){
    // Output: 2
    vector<int>nums={1,0,2,0,3};
    // Output: 0
    vector<int>nums2={2,3,4,0,4,1,0};
    cout<<countValidSelections(nums)<<endl;
    cout<<countValidSelections(nums2);
    return 0;
}