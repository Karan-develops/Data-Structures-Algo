// Insertion Sort
// T.C - O(n^2)
#include<iostream>
#include<vector>
using namespace std;
void insertionSort(vector<int>&nums){
    int n=nums.size();

    for(int i=1;i<n;i++){
        // element to insert
        int key=nums[i];
        int j=i-1;

        // shift elements greater than key to the right
        while(j>=0 && nums[j]>key){
            nums[j+1]=nums[j];
            j--;
        }
        
        // place key at correct position
        nums[j+1]=key;
    }
}
int main(){
    // Output: [1,2,3,5]
    vector<int>nums={5,2,3,1};
    // Output: [0,0,1,1,2,5]
    vector<int>nums2={5,1,1,2,0,0};
    
    insertionSort(nums);
    for(int &i:nums) cout<<i<<" ";
    return 0;
}