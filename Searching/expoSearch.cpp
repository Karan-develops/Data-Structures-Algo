#include<iostream>
#include<vector>
using namespace std;
int binarySearch(vector<int>v,int s,int e,int target){
    int mid=s+(e-s)/2;
    while(s<=e){
        if(v[mid]==target){
            return mid;
        }
        else if(v[mid]>target){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return -1;
}
int expoSearch(vector<int>v,int n,int target){
    if(v[0]==target) return 0;
    int i=1;
    while(i<n && v[i]<=target){
        i*=2;
    }
    int ans=binarySearch(v,i>>1,min(i,n-1),target);
    return ans;
}
int main(){
    vector<int>v{3,4,5,6,11,13,14,15,56,70};
    int n=v.size();
    int target;
    cout<<"Enter Target:";
    cin>>target;
    int ans=expoSearch(v,n,target);
    cout<<"Target is found at index:"<<ans;
    return 0;
}