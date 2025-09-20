// LC - 2197 - HARD - Replace Non-Coprime Numbers in Array
#include<iostream>
#include<vector>
#include<stack>
#include<numeric>
using namespace std;
vector<int> replaceNonCoprimes(vector<int>&nums){
    vector<int>ans;

    // Processing left to right
    for(int num:nums){
        while(!ans.empty()){
            int prev=ans.back();
            int curr=num;

            int GCD=gcd(prev,curr);

            if(GCD==1) break;

            ans.pop_back();
            int LCM=prev/GCD*curr;

            // merged number
            num=LCM;
        }
        // merged num put back to ans
        ans.push_back(num);
    }
    return ans;
}
int main(){
    // Output: [12,7,6]
    vector<int>nums={6,4,3,2,7,6,2};
    // Output: [2,1,1,3]
    vector<int>nums2={2,2,1,1,3,3,3};
    return 0;
}