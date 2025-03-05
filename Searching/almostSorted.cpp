#include<iostream>
#include<vector>
using namespace std;
int main(){
    int target;
    vector<int>v{10,3,40,20,50,80,70};
    cout<<"Enter target:";
    cin>>target;
    int start=0;
    int end=v.size()-1;
    int mid=start+(end-start)/2;
    int ans=-1;
    while(start<=end){
        if(v[mid]==target){
            ans=mid;
            break;
        }
        if(v[mid+1]==target){
            ans=mid+1;
            break;
        }
        if(v[mid-1]==target){
            ans=mid-1;
            break;
        }
        else if(v[mid]>target){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
        mid=start+(end-start)/2;
    }
    if(ans>0){
        cout<<"Target found at index:"<<ans;
    }
    else{
        cout<<"Not found!";
    }
    return 0;
}