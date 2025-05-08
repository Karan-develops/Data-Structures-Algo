// LC - 2090 - Medium - K Radius Subarray Averages
#include<iostream>
#include<vector>
using namespace std;
vector<int> getAverages(vector<int>&nums,int k){
    int n=nums.size();
        
    if(k==0) return nums;

    vector<int> ans(n,-1);
    if(n<2*k + 1) return ans;
    
    long long windowSum=0;
    
    int left=0;
    int right=2*k;
    int i=k;
    
    for(int i=left;i<=right;i++){
        windowSum+=nums[i];
    }
    
    ans[i]=windowSum/(2*k+1);
    
    i++;
    right++; //Shifting window
    
    while(right<n){
        int out_of_window=nums[left];
        int came_to_window=nums[right];
        
        windowSum+=came_to_window+out_of_window;
        
        ans[i]=windowSum/(2*k+1);
        i++;
        left++;
        right++;
    }
    return ans;
}
int main(){
    // Output: [-1,-1,-1,5,4,4,-1,-1,-1]
    vector<int>nums={7,4,3,9,1,8,5,2,6};
    int k=3;
    // Output: [100000]
    vector<int>nums2={100000};
    int k2=0;
    // Output: [-1]
    vector<int>nums3={8};
    int k3=100000;
    return 0;
}