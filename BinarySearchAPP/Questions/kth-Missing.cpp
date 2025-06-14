// LC - 1539 - Easy - Kth Missing Positive Number
#include<iostream>
#include<vector>
using namespace std;
// Approach 1 - Naive ( Linear )
int findKthPositive(vector<int>&arr,int k){
    int n=arr.size();
    int num=1;
    int i=0;

    while(i<n && k>0){
        if(arr[i]==num) i++;
        else k--;

        num++;
    }
    // For cases like {1,2,3} k=2 => (Ans=5)
    while(k--) num++;

    return num-1;
}
int findKthPositiveBinary(vector<int>& arr, int k) {
    int n=arr.size();
    int l=0,r=n-1;
    
    while(l<=r){
        int mid=l+(r-l)/2;
        
        // A[mid]-(mid+1) --> This gives number of missing number before m'th index
        if(arr[mid]-(mid+1)<k){
            l=mid+1;
        } else{
            r=mid-1;
        }   
    }
    return l+k;
}
int main(){
    // Output: 9
    vector<int>arr={2,3,4,7,11};
    int k=5;
    // Output: 6
    vector<int>arr2={1,2,3,4};
    int k2=2;
    cout<<findKthPositive(arr,k)<<endl;
    cout<<findKthPositive(arr2,k2);
    return 0;
}