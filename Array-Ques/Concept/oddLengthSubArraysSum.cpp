// LC - 1588 - Easy - Sum of All Odd Length Subarrays
#include<iostream>
#include<vector>
using namespace std;
int sumOddLengthSubarrays(vector<int>&arr){
    int n=arr.size();
    int ans=0;

    for(int i=0;i<n;i++){
        // 0 to i elements will make subarray with this element
        int left=i+1;
        // i to n elements will make subarray with this element
        int right=n-i;
        
        int totalSum=left*right;
        int oddSubArrays=(totalSum+1)/2;

        ans+=arr[i]*oddSubArrays;
    }
    return ans;
}
int main(){
    // Output: 58
    vector<int>arr={1,4,2,5,3};
    // Output: 3
    vector<int>arr2={1,2};
    // Output: 66
    vector<int>arr3={10,11,12};
    cout<<sumOddLengthSubarrays(arr)<<endl;
    cout<<sumOddLengthSubarrays(arr2)<<endl;
    cout<<sumOddLengthSubarrays(arr3);
    return 0;
}