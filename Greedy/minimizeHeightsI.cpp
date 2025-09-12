// GFG - Minimize the Heights I
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int getMinDiff(vector<int>&arr,int k){
    int n=arr.size();
    
    sort(begin(arr),end(arr));
    
    int minH=arr[0];
    int maxH=arr[n-1];
    
    int ans=maxH-minH;
    
    for(int i=1;i<n;i++){
        minH=min(arr[0]+k,arr[i]-k);
        maxH=max(arr[i-1]+k,arr[n-1]-k);
        
        ans=min(ans,maxH-minH);
    }
    return ans;
}
int main(){
    // Output: 5
    int k=2;
    vector<int>arr={1,5,8,10};
    // Output: 11
    int k2=3;
    vector<int>arr2={3,9,12,16,20};
    cout<<getMinDiff(arr,k)<<endl;
    cout<<getMinDiff(arr2,k2);
    return 0;
}