// GFG - Group Balls by Sequence
#include<iostream>
#include<vector>
#include<map>
using namespace std;
bool validgroup(vector<int>&arr,int k){
    int n=arr.size();
    map<int,int>mp;

    for(int &i:arr) mp[i]++;

    for(auto &it:mp){
        int val=it.first;
        int freq=it.second;

        if(freq==0) continue;

        for(int i=1;i<k;i++){
            int nextVal=val+i;

            if(mp[nextVal]<freq) return false;

            mp[nextVal]-=freq;
        }
    }
    return true;
}
int main(){
    // Output: true
    vector<int>arr={10,1,2,11};
    int k=2;
    // Output: false
    vector<int>arr2={7,8,9,10,11};
    int k2=2;
    cout<<validgroup(arr,k)<<endl;
    cout<<validgroup(arr2,k2);
    return 0;
}