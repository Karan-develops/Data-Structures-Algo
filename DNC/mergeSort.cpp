#include<iostream>
using namespace std;
void merge(int* arr,int s,int e){
    int mid=(s+e)/2;
    int s1=mid-s+1;
    int s2=e-mid;
    // create dynamic arrays
    int* leftArr=new int[s1];
    int* rightArr=new int[s2];
    // Copy values
    int k=s;
    for(int i=0;i<s1;i++){
        leftArr[i]=arr[k++];
    }
    k=mid+1;
    for(int i=0;i<s2;i++){
        rightArr[i]=arr[k++];
    }
    // merge 2 arrays logic
    int leftIdx=0;
    int rightIdx=0;
    int mainArrayIdx=s;
    while(leftIdx<s1 && rightIdx<s2){
        if(leftArr[leftIdx]<rightArr[rightIdx]){
            arr[mainArrayIdx++]=leftArr[leftIdx++];
        } else{
            arr[mainArrayIdx++]=rightArr[rightIdx++];
        }
    }
    while(leftIdx<s1){
        arr[mainArrayIdx++]=leftArr[leftIdx++];
    }
    while(rightIdx<s2){
        arr[mainArrayIdx++]=rightArr[rightIdx++];
    }
    delete[] leftArr;
    delete[] rightArr;
}
void mS(int* arr,int s,int e){
    if(s>=e) return;
    int mid=(s+e)/2;
    // break and sort left part by recursion
    mS(arr,s,mid);
    // break and sort right part by recursion
    mS(arr,mid+1,e);
    // merge them
    merge(arr,s,e);
}
int main(){
    int arr[]={6,1,5,12,2,8};
    int n=sizeof(arr)/sizeof(int);
    mS(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}