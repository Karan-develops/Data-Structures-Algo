#include<iostream>
#include<vector>
using namespace std;
int partition(vector<int>&arr,int low,int high){
    int pivot=arr[high];
    int pivotIndex=low;
    for(int i=low;i<high;i++){
        if(arr[i]<=pivot) swap(arr[i],arr[pivotIndex++]);
    }
    swap(arr[high],arr[pivotIndex]);
    return pivotIndex;
}
void quickSort(vector<int>&arr,int low,int high){
    if(low>=high) return;
    int Pi=partition(arr,low,high);
    quickSort(arr,low,Pi-1);
    quickSort(arr,Pi+1,high);
}
int main(){
    vector<int>arr={3,2,1,5,0,3,5,2,1,8,1,6};
    quickSort(arr,0,arr.size()-1);
    for(int &i:arr) cout<<i<<" ";
    return 0;
}