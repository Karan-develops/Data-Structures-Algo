// LC - 1282 - Medium - Group the People Given the Group Size They Belong To
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<vector<int>> groupThePeople(vector<int>&groupSizes){
    vector<vector<int>>ans;
    unordered_map<int,vector<int>>mp;
    int n=groupSizes.size();
    for(int i=0;i<n;i++){
        int gSize=groupSizes[i];
        mp[gSize].push_back(i);

        if(mp[gSize].size()==gSize){
            ans.push_back(mp[gSize]);
            mp[gSize].clear();
        }
    }
    return ans;
}
int main(){
    // Output: [[5],[0,1,2],[3,4,6]]
    vector<int>groupSizes={3,3,3,3,3,1,3};
    // Output: [[1],[0,5],[2,3,4]]
    vector<int>groupSizes2={2,1,3,3,3,2};
    return 0;
}