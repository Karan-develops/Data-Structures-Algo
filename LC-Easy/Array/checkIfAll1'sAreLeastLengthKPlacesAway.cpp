// LC - 1437 - Easy - Check If All 1's Are at Least Length K Places Away
#include<iostream>
#include<vector>
using namespace std;
bool kLengthApart(vector<int>&nums,int k){
    int n=nums.size();
    
    int lastOne=-(k+1);

    for(int i=0;i<n;i++){
        if(nums[i]==1){
            if(i-lastOne-1<k) return false;
            
            lastOne=i;
        }
    }

    return true;
}
int main(){
    // Output: true
    vector<int>nums={1,0,0,0,1,0,0,1};
    int k=2;
    // Output: false
    vector<int>nums2={1,0,0,1,0,1};
    int k2=2;
    cout<<kLengthApart(nums,k)<<endl;
    cout<<kLengthApart(nums2,k2);
    return 0;
}