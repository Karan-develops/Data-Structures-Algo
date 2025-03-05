#include<iostream>
#include<numeric>
using namespace std;
bool isPossibleSolution(int arr[],int size,int mid,int students){
    int pageSum=0;
    int count=1;
    for(int i=0;i<size;i++){
        if(arr[i]>mid){
            return false;
        }
        if(pageSum+arr[i]>mid){
            count++;
            pageSum=arr[i];
            if(count>students){
                return false;
            }
        }
        else{
            pageSum+=arr[i];
        }
    }
    return true;
}
int bookAllo(int arr[],int students,int size){
    if(size<students){
        return -1;
    }
    int start=0;
    int end=accumulate(arr,arr+size,0);
    int ans=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(isPossibleSolution(arr,size,mid,students)){
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
    int arr[4]={12,34,67,90};
    int size=4;
    int students;
    cout<<"Enter number of students:";
    cin>>students;
    int ans=bookAllo(arr,students,size);
    cout<<"The correct Allocation is:"<<ans;
    return 0;
}