#include<iostream>
#include<algorithm>
using namespace std;
bool isPossibleSolution(int trees[],int size,int wood,int mid){
    int woodCollected=0;
    for(int i=0;i<size;i++){
        if(trees[i]>mid){
            woodCollected+=trees[i]-mid;
        }
    }
    return woodCollected>=wood;
}
int spoj(int trees[],int size,int wood){
    int start=0;
    int end=*max_element(trees,trees+size);
    int ans=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(isPossibleSolution(trees,size,wood,mid)){
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
    int trees[4]={20,15,10,17};
    int size=4;
    int woodRqd;
    cout<<"Enter the wood required:";
    cin>>woodRqd;
    int ans=spoj(trees,size,woodRqd);
    cout<<"The cut will done at height: "<<ans<<" units";
    return 0;
}