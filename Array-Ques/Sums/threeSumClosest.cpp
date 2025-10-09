// LC - 16 - Medium - 3Sum Closest
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int threeSumClosest(vector<int>&nums,int target){
    int n=nums.size();
    
    sort(nums.begin(),nums.end());
    
    int closestSum=100000;
    
    for(int k=0;k<n-2;k++){
        int i=k+1;
        int j=n-1;
        
        while(i<j){
            int sum=nums[i]+nums[j]+nums[k];
            
            if(abs(target-sum)<abs(target-closestSum)){
                closestSum=sum;
            }
            
            if(sum<target) i++;
            else j--;
        }
    }
    return closestSum;
}
int main(){
    // Output: 2
    vector<int>nums={-1,2,1,-4};
    int target=1;
    // Output: 0
    vector<int>nums2={0,0,0};
    int target2=1;
    cout<<threeSumClosest(nums,target)<<endl;
    cout<<threeSumClosest(nums2,target2);
    return 0;
}