// LC - 1574 - Medium - Shortest Subarray to be Removed to Make Array Sorted
#include<iostream>
#include<vector>
using namespace std;
int findLengthOfShortestSubarray(vector<int>&arr){
    int n=arr.size();
    int j=n-1;

    while(j>0 && arr[j]>=arr[j-1]) j--;
    if(j==0) return 0;
    
    int i=0;
    int ans=j;

    while(i<j && (i==0 || arr[i]>=arr[i-1])){
        while(j<n && arr[i]>arr[j]) {
            cout<<i<<" "<<j<<endl;
            j++;}

        ans=min(ans,j-i-1);
        i++;
    }
    return ans;
}
int main(){
    // Output: 3
    vector<int>arr={1,2,3,10,4,2,3,5};
    // Output: 4
    vector<int>arr2={5,4,3,2,1};
    // Output: 0
    vector<int>arr3={1,2,3};
    cout<<findLengthOfShortestSubarray(arr)<<endl;
    cout<<findLengthOfShortestSubarray(arr2)<<endl;
    cout<<findLengthOfShortestSubarray(arr3);
    return 0;
}