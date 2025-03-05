#include<iostream>
using namespace std;
int fact(int n){
    if(n==0 || n==1) return n;
    return n*fact(n-1);
}
int fibbo(int n){
    if(n==0 || n==1) return n;
    return fibbo(n-1)+fibbo(n-2);
}
void printArr(int arr[],int i,int n){
    if(i>=n) return;
    cout<<arr[i]<<" ";
    printArr(arr,i+1,n);
}
int main(){
    int n=5;
    int ans1=fact(n);
    cout<<"Factorial:"<<ans1<<endl;
    int ans2=fibbo(n);
    cout<<"Fibbo Element:"<<ans2<<endl;
    int arr[5]={10,20,30,40,50};
    int i=0;
    int sarr=5;
    printArr(arr,i,n);
    return 0;
}