// LC - 66 - Easy Plus One
#include<iostream>
#include<vector>
using namespace std;
vector<int> plusOne(vector<int>&digits){
    int n=digits.size();
    for(int i=n-1;i>=0;i--){
        if(i==n-1) digits[i]++;
        if(digits[i]==10){
            digits[i]=0;
            if(i!=0) digits[i-1]++;
            else{
                digits.push_back(0);
                digits[i]=1;
            }
        }
    }
    return digits;
}
int main(){
    // OP - [1,2,4]
    vector<int>nums1={1,2,3};
    // OP - [4,3,2,2]
    vector<int>nums2={4,3,2,1};
    // OP - [1,0]
    vector<int>nums3={9};
    vector<int>ans=plusOne(nums1);
    for(int &i:ans) cout<<i<<" ";
    return 0;
}