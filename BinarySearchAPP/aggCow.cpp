#include<iostream>
using namespace std;
bool isPossibleSolution(int stalls[],int size,int cows,int mid){
    int count=1;
    int pos=stalls[0];
    for(int i=1;i<size;i++){
        if(stalls[i]-pos>=mid){
            count++;
            pos=stalls[i];
        }
        if(cows==count){
            return true;
        }
    }
    return false;
}
int aggCows(int stalls[],int size,int cows){
    int start=0;
    int end=stalls[size-1]-stalls[0];
    int ans=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(isPossibleSolution(stalls,size,cows,mid)){
            ans=mid;
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return ans;
}
int main(){
    int stalls[5]={1,2,4,8,9};
    int size=5;
    int cows;
    cout<<"Enter number of cows:";
    cin>>cows;
    int ans=aggCows(stalls,size,cows);
    cout<<"The maximum minimum distance between cows is:"<<ans;
    return 0;
}