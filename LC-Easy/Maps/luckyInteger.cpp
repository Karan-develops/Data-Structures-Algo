// LC - 1394 - Easy - Find Lucky Integer in an Array
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int findLucky(vector<int>&arr){
    int n=arr.size();
    unordered_map<int,int>mp;

    for(int &i:arr) mp[i]++;

    int ans=-1;
    for(int i=0;i<n;i++){
        if(mp[i+1]==i+1){
            ans=max(ans,i+1);
        }
    }
    return ans;
}
int main(){
    // Output: 2
    vector<int>arr={2,2,3,4};
    // Output: 3
    vector<int>arr2={1,2,2,3,3,3};
    // Output: -1
    vector<int>arr3={2,2,2,3,3};
    cout<<findLucky(arr)<<endl;
    cout<<findLucky(arr2)<<endl;
    cout<<findLucky(arr3);
    return 0;
}