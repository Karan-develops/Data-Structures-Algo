// LC - 977 - Easy - Squares of a Sorted Array
#include<iostream>
#include<vector>
using namespace std;
// Approach 1 - Just Use sort after squaring
// Approach 2 - Two Pointers
vector<int> sortedSquares(vector<int>&nums){
    int n=nums.size();

    vector<int>ans(n);

    int i=0,j=n-1;
    
    for(int k=n-1;k>=0;k--){
        int a=nums[i]*nums[i];
        int b=nums[j]*nums[j];

        if(a<b){
            ans[k]=b;
            j--;
        } else{
            ans[k]=a;
            i++;
        }
    }
    return ans;
}
int main(){
    // Output: [0,1,9,16,100]
    vector<int>nums={-4,-1,0,3,10};
    // Output: [4,9,9,49,121]
    vector<int>nums2={-7,-3,2,3,11};
    return 0;
}