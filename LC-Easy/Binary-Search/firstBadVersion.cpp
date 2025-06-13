// LC - 278 - Easy - First Bad Version
/*
You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.
*/
#include<iostream>
using namespace std;
// Demo Function
bool isBadVersion(int mid){
    return true;
}
int firstBadVersion(int n){
    int l=0,r=n;
    int ans=0;

    while(l<=r){
        int mid=l+(r-l)/2;
        if(isBadVersion(mid)){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    return ans;
}
int main(){
    // Output: 4
    int n=5,bad=4;
    // Output: 1
    int n2=1,bad2=1;
    cout<<firstBadVersion(n)<<endl;
    cout<<firstBadVersion(n2);
    return 0;
}