#include<iostream>
using namespace std;
void solve(int arr[],int i,int n,int sum,int& maxi){
    if(i>=n){
        maxi=max(sum,maxi);
        return;
    }
    // include
    solve(arr,i+2,n,sum+arr[i],maxi);
    // exclude
    solve(arr,i+1,n,sum,maxi);
}
int main(){
    int arr[4]={2,1,4,9};
    int i=0,n=4;
    int sum=0;
    int maxi=INT_MIN;
    solve(arr,i,n,sum,maxi);
    cout<<"Answer is: "<<maxi;
    return 0;
}