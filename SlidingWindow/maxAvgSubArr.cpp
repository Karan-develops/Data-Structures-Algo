// LC - 643 - Easy - Maximum Average Subarray I
#include<iostream>
#include<vector>
using namespace std;
double findMaxAverage(vector<int>& nums, int k) {
    int n=nums.size();
    double ans=INT_MIN;
    int i=0,j=0;
    double sum=0;
    while(j<n){
        sum+=nums[j];
        if(j+1>=k){
            ans=max(ans,sum/k);
            sum-=nums[i];
            i++;
        }
        j++;
    }
    return ans;
}
int main(){
    // Output: 12.75000
    vector<int>nums={1,12,-5,-6,50,3};
    int k=4;
    // Output: 5.00000
    vector<int>nums2={5};
    int k2=1;
    cout<<findMaxAverage(nums,k)<<endl;
    cout<<findMaxAverage(nums2,k2);
    return 0;
}