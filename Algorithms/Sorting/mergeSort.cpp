// Merge Sort
// T.C : O(nlogn)
// S.C : O(n)
#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>&arr,int s,int e,int mid){
    int m=mid-s+1;
    int n=e-mid;

    int leftArray[m],rightArray[n];
    
    int k=s;
    
    for(int i=0;i<m;i++) leftArray[i]=arr[k++];
    for(int j=0;j<n;j++) rightArray[j]=arr[k++];
    
    int i=0,j=0;
    k=s;

    while(i<m && j<n){
        if(leftArray[i]<=rightArray[j]){
            arr[k++]=leftArray[i++];
        } else{
            arr[k++]=rightArray[j++];
        }
    }

    while(i<m) arr[k++]=leftArray[i++];
    while(j<n) arr[k++]=rightArray[j++];
}
void mergeSort(vector<int>&arr,int l,int r){
    if(l>=r) return;
    
    int mid=l+(r-l)/2;
    
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    
    merge(arr,l,r,mid);
}
int main(){
    vector<int>arr={3,2,1,5,0,3,5,2,1,8,1,6};
    int n=arr.size()-1;
    
    mergeSort(arr,0,n);
    for(int &i:arr) cout<<i<<" ";
    return 0;
}