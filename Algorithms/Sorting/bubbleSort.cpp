// Bubble Sort
// T.C - O(n^2)
#include<iostream>
#include<vector>
using namespace std;
void bubbleSort(vector<int>&nums,int n){
    for(int i=0;i<n;i++){
        bool swapped=false;
        
        for(int j=0;j<n-i-1;j++){
            if(nums[j]>nums[j+1]){
                swap(nums[j],nums[j+1]);
                swapped=true;
            }
        }
        
        if(!swapped) break;
    }
}
int main(){
    // Output: [1,2,3,5]
    vector<int>nums={5,2,3,1};
    // Output: [0,0,1,1,2,5]
    vector<int>nums2={5,1,1,2,0,0};
    return 0;
}