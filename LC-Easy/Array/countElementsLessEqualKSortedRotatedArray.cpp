// GFG - Medium - Count elements less than or equal to k in a sorted rotated array
// Also using binary search
#include<iostream>
#include<vector>
using namespace std;
int countLessEqual(vector<int>&arr,int x){
    int ans=0;
    
    for(int &i:arr){
        if(i<=x) ans++;
    }
    
    return ans;
}
int main(){
    // Output: 4
    int x=6;
    vector<int>arr={4,5,8,1,3};
    // Output: 6
    int x2=14;
    vector<int>arr2={6,10,12,15,2,4,5};
    cout<<countLessEqual(arr,x)<<endl;
    cout<<countLessEqual(arr2,x2);
    return 0;
}