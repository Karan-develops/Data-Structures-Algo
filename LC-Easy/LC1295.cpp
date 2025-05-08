//LC - 1295 - Easy - Find Numbers with Even Number of Digits
#include<iostream>
#include<vector>
using namespace std;
int findNumbers(vector<int>&nums){
    int ans=0;
    for(int &i:nums){
        if((i>=10 && i<100) || (i>=1000 && i<10000) || i==100000) ans++;
    }
    return ans;
}
int main(){
    // Output: 2
    vector<int>nums={12,345,2,6,7896};
    // Output: 1
    vector<int>nums2={555,901,482,1771};
    cout<<findNumbers(nums)<<endl;
    cout<<findNumbers(nums2);
    return 0;
}
