//T.C : O(nlogn)
//S.C : O(n)
#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>&arr,int s,int e,int mid){
    int n1=mid-s+1;
    int n2=e-mid;
    int leftArray[n1],rightArray[n2];
    int k=s;
    for(int i=0;i<n1;i++) leftArray[i]=arr[k++];
    for(int j=0;j<n2;j++) rightArray[j]=arr[k++];
    int i=0,j=0;
    k=s;
    while(i<n1 && j<n2){
        if(leftArray[i]<=rightArray[j]){
            arr[k++]=leftArray[i++];
        } else{
            arr[k++]=rightArray[j++];
        }
    }
    while(i<n1) arr[k++]=leftArray[i++];
    while(j<n2) arr[k++]=rightArray[j++];
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