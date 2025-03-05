#include<iostream>
#include<numeric>
using namespace std;
bool isPossibleSolution(int arr[],int size,int mid,int painters){
    int timeSum=0;
    int count=1;
    for(int i=0;i<size;i++){
        if(arr[i]>mid){
            return false;
        }
        if(arr[i]+timeSum>mid){
            count++;
            timeSum=arr[i];
            if(count>painters){
                return false;
            }
        }
        else{
            timeSum+=arr[i];
        }
    }
    return true;
}
int painter(int arr[],int size,int painters){
    if(painters>size){
        return -1;
    }
    int start=0;
    int end=accumulate(arr,arr+size,0);
    int ans=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(isPossibleSolution(arr,size,mid,painters)){
            ans=mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return ans;
}
int main(){
    int arr[5]={5,10,30,20,15};
    int size=5;
    int painters;
    cout<<"Enter number of painters:";
    cin>>painters;
    int ans=painter(arr,size,painters);
    cout<<"The minimum time is:"<<ans<<" minutes";
    return 0;
}