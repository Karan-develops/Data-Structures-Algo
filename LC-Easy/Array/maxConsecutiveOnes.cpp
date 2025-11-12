// LC - 485 - Easy - Max Consecutive Ones
#include<iostream>
#include<vector>
using namespace std;
int findMaxConsecutiveOnes(vector<int>&nums){
    int curr=0,ans=0;

    for(int &i:nums){
        if(i==1) curr++;
        else{
            ans=max(ans,curr);
            curr=0;
        }
    }

    return max(ans,curr);
}
int main(){
    // Output: 3
    vector<int>nums={1,1,0,1,1,1};
    // Output: 2
    vector<int>nums2={1,0,1,1,0,1};
    cout<<findMaxConsecutiveOnes(nums)<<endl;
    cout<<findMaxConsecutiveOnes(nums2);
    return 0;
}