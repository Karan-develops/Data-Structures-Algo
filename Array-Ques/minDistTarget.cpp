// LC - 1848 - Easy - Minimum Distance to the Target Element
#include<iostream>
#include<vector>
using namespace std;
int getMinDistance(vector<int>&nums,int target,int start){
    int n=nums.size();
    int ans=INT_MAX;

    for(int i=0;i<n;i++){
        if(nums[i]==target){
            ans=min(ans,abs(i-start));
        }
    }
    return ans;
}
int main(){
    // Output: 1
    vector<int>nums={1,2,3,4,5};
    int target=5,start=3;
    // Output: 0
    vector<int>nums2={1};
    int target2=1,start2=0;
    // Output: 0
    vector<int>nums3={1,1,1,1,1,1,1,1,1,1};
    int target3=1,start3=0;
    cout<<getMinDistance(nums,target,start)<<endl;
    cout<<getMinDistance(nums2,target2,start2)<<endl;
    cout<<getMinDistance(nums3,target3,start3);
    return 0;
}