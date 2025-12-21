// GFG - Medium - Count X in Range of a Sorted Array
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
vector<int> countXInRange(vector<int>&arr,vector<vector<int>>&queries){
    unordered_map<int,vector<int>>mp;
    int n=arr.size();

    for(int i=0;i<n;i++){
        mp[arr[i]].push_back(i);
    }
    
    vector<int>ans;

    for(auto &vec:queries){
        int l=vec[0];
        int r=vec[1];
        int x=vec[2];

        if(!mp.count(x)){
            ans.push_back(0);
            continue;
        }

        auto &v=mp[x];
        int left=lower_bound(begin(v),end(v),l)-begin(v);
        int right=upper_bound(begin(v),end(v),r)-begin(v);

        ans.push_back(right-left);
    }

    return ans;
}
int main(){
    // Output: [3, 2, 0]
    vector<int>arr={1,2,2,4,5,5,5,8};
    vector<vector<int>>queries={{0,7,5},{1,2,2},{0,3,7}};
    // Output: [3, 0, 1]
    vector<int>arr2={1,3,3,3,6,7,8};
    vector<vector<int>>queries2={{0,3,3},{4,6,3},{1,5,6}};
    return 0;
}