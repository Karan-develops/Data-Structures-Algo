#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>arr{0,10,5,2};
    int start=0;
    int end=arr.size()-1;
    int mid=start+(end-start)/2;
    int peak=-1;
    while(start<end){
        if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]){
            peak=arr[mid];
            break;
        }
        else if(arr[mid]<arr[mid+1]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    cout<<peak;
}