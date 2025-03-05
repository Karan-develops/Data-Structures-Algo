#include<iostream>
using namespace std;
int main(){
    int arr[5][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16},{17,18,19,20}};
    int target;
    cout<<"Enter target element:";
    cin>>target;
    int rows=5;
    int cols=4;
    int start=0;
    int size=rows*cols;
    int end=size-1;
    int mid=start+(end-start)/2;
    int ans=-1;
    while(start<=end){
        int rowIndex=mid/cols;
        int colIndex=mid%cols;
        if(arr[rowIndex][colIndex]==target){
            ans=1;
            break;
        }
        else if(arr[rowIndex][colIndex]>target){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
        mid=start+(end-start)/2;
    }
    cout<<ans;
    return 0;
}