// Kadane’s Algorithm is used to find the maximum subarray sum in an array
#include<iostream>
#include<vector>
using namespace std;
int kadane(vector<int>&nums){
    int maxSum=INT_MIN;
    int currSum=0;
    for(int &i:nums){
        currSum=max(i,currSum+i);
        maxSum=max(maxSum,currSum);
    }
    return maxSum;
}
int main(){
    vector<int>arr={-2,1,-3,4,-1,2,1,-5,4};
    cout<<kadane(arr);
    return 0;
}
// We can also find minimum sum just by using min instead of max.