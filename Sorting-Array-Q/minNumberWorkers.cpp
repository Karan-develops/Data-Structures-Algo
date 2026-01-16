// GFG - Medium - Minimum Number of Workers
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int minMen(vector<int>&arr){
    int n=arr.size();
    vector<pair<int,int>>intervals;

    for(int i=0;i<n;i++){
        if(arr[i]!=-1){
            int L=max(0,i-arr[i]);
            int R=min(n-1,i+arr[i]);
            intervals.push_back({L,R});
        }
    }

    sort(begin(intervals),end(intervals));

    int curr=0,ans=0;
    int i=0,m=intervals.size();

    while(curr<n){
        int farthest=curr-1;

        // Choose interval that starts before/equal curr and extends farthest
        while(i<m && intervals[i].first<=curr){
            farthest=max(farthest,intervals[i].second);
            i++;
        }

        // Cannot extend coverage
        if(farthest<curr) return -1;

        ans++;
        curr=farthest+1;
    }

    return ans;
}
int main(){
    // Output: 1
    vector<int>arr={1,2,1,0};
    // Output: -1
    vector<int>arr2={2,3,4,-1,2,0,0,-1,0};
    // Output: -1
    vector<int>arr3={0,1,0,-1};
    cout<<minMen(arr)<<endl;
    cout<<minMen(arr2)<<endl;
    cout<<minMen(arr3);
    return 0;
}