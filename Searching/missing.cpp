#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v{1,2,3,4,6,7,8};
    int start=0;
    int end=v.size()-1;
    int mid=start+(end-start)/2;
    int missing=-1;
    while(start<=end){
        if(v[mid]==mid+1){
            start=mid+1;
        } else{
            missing=mid+1;
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    cout<<missing;
    return 0;
}