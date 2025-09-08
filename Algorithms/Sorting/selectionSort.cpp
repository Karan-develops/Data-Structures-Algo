// Selection Sort
// T.C - O(n^2)
#include<iostream>
#include<vector>
using namespace std;
void selectionSort(vector<int>&nums){
    int n=nums.size();

    for(int i=0;i<n-1;i++){
        int minIndex=i;

        // find the minimum element in the remaining array
        for(int j=i+1;j<n;j++){
            if(nums[j]<nums[minIndex]){
                minIndex=j;
            }
        }

        // swap with the first element of unsorted part
        swap(nums[i],nums[minIndex]);
    }
}
int main(){
    // Output: [1,2,3,5]
    vector<int>nums={5,2,3,1};
    // Output: [0,0,1,1,2,5]
    vector<int>nums2={5,1,1,2,0,0};

    selectionSort(nums2);
    for(int &i:nums2) cout<<i<<" ";
    return 0;
}