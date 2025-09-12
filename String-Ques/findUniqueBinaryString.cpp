// LC - 1980 - Medium - Find Unique Binary String
#include<iostream>
#include<vector>
using namespace std;
string findDifferentBinaryString(vector<string>&nums){
    int n=nums.size();
    string ans;
    
    for(int i=0;i<n;i++){
        char ch=nums[i][i];
        
        ans+=(ch=='0')?"1":"0";
    }
    return ans;
}
int main(){
    // Output: "11"
    vector<string>nums={"01","10"};
    // Output: "11"
    vector<string>nums2={"00","01"};
    // Output: "101"
    vector<string>nums3={"111","011","001"};
    cout<<findDifferentBinaryString(nums)<<endl;
    cout<<findDifferentBinaryString(nums2)<<endl;
    cout<<findDifferentBinaryString(nums3);
    return 0;
}