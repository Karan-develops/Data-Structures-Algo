#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v{1,2,3,4,4,4,4,6,7};
    short target;
    cout<<"Enter Target:";
    cin>>target;
    int val=-1;
    int start=0;
    int end=v.size()-1;
    int mid=start+(end-start)/2;
    while(start<=end){
        if(target==v[mid]){
            val=mid;
            end=mid-1;
        }
        else if(target>v[mid]) start=mid+1;
        else end=mid-1;
        mid=start+(end-start)/2;
    }
    cout<<val;
}