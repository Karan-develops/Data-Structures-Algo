// Dutch National Flag Algorithm
#include<iostream>
using namespace std;
void moveNegatives(int *a,int n){
    int l=0;
    int h=n-1;
    while(l<h){
        if(a[l]<0) l++;
        else if(a[h]>0) h--;
        else swap(a[l],a[h]);
    }
}
int main(){
    int a[]={3,-1,5,-5,-2,4,9,-1,2};
    int n=sizeof(a)/sizeof(int);
    moveNegatives(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}