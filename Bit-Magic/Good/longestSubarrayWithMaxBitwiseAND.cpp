// LC - 2419 - Medium - Longest Subarray With Maximum Bitwise AND
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Max AND is only possible when all elements in subarray are equal to maxE.
int longestSubarray(vector<int>&nums){
    int ans=0;
    int maxVal=0,window=0;

    for(int &i:nums){
        if(i>maxVal){
            maxVal=i;
            window=0;
            ans=0;
        }

        if(i==maxVal) window++;
        else window=0;
        
        ans=max(ans,window);
    }
    return ans;
}
// We can also convert this into sliding window
int longestSubarray2(vector<int>&nums){
    int n=nums.size();
    
    int ans=0;
    int maxVal=*max_element(begin(nums),end(nums));

    int i=0,j=0;

    while(j<n){
        if(nums[j]==maxVal){
            ans=max(ans,j-i+1);
            j++;
        } else{
            // Firstly do j++ to exclude current element in next window
            j++;
            i=j;
        }
    }
    return ans;
}
int main(){
    // Output: 2
    vector<int>nums={1,2,3,3,2,2};
    // Output: 1
    vector<int>nums2={1,2,3,4};
    cout<<longestSubarray(nums)<<endl;
    cout<<longestSubarray(nums2);
    return 0;
}