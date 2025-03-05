#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v{1,1,2,2,3,3,4,4,3,3,600,600,5,4,4};
    int start=0;
    int end=v.size()-1;
    int mid=start+(end-start)/2;
    int ans=-1;
    while(start<=end){
        if(start==end){
            ans=v[start];
            break;
        }
        else if(mid%2==0){
            if(v[mid]==v[mid+1]){
                start=mid+2;
            }
            else{
                end=mid;
            }
        }
        else{
            if(v[mid]==v[mid-1]){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        mid=start+(end-start)/2;
    }
    cout<<"ODD Occuring element is:"<<ans;
    return 0;
}