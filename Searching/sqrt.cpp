#include<iostream>
using namespace std;
int main(){
    int target;
    cout<<"Enter a number:";
    cin>>target;
    int start=0;
    int end=target;
    int ans=-1;
    int mid=start+(end-start)/2;
    while(start<=end){
        if(mid*mid==target){
            ans=mid;
            break;
        }
        else if(mid*mid>target){
            end=mid-1;
        }
        else{
            ans=mid; // store the ans
            start=mid+1;
        }
        mid=start+(end-start)/2;
    }
    cout<<ans;
    return 0;
}