#include<iostream>
using namespace std;
int findSqrt(int n){
    int start=0;
    int end=n;
    int mid=start+(end-start)/2;
    int ans=-1;
    while(start<=end){
        if(mid*mid==n){
            ans=mid;
            break;
        }
        else if(mid*mid>n){
            end=mid-1;
        }
        else{
            ans=mid;
            start=mid+1;
        }
        mid=start+(end-start)/2;
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter the number:";
    cin>>n;
    int ans=findSqrt(n);
    cout<<"Approximate Square-Root is:"<<ans<<endl;
    double finalAns=ans;
    int precision=5;
    double step=0.1;
    for(int i=0;i<precision;i++){
        for(double j=finalAns;j*j<=n;j=j+step){
            finalAns=j;
        }
        step/=10;
    }
    cout<<"Floating Square-Root is:"<<finalAns;
    return 0;
}