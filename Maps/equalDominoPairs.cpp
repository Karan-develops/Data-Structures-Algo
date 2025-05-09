// LC - 1128 - Easy - Number of Equivalent Domino Pairs
#include<iostream>
#include<vector>
#include<map>
using namespace std;
int numEquivDominoPairs(vector<vector<int>>&dominoes){
    map<pair<int,int>,int>mp;
    for(auto &d:dominoes){
        if(d[0]<d[1]) swap(d[0],d[1]);
        mp[{d[0],d[1]}]++;
    }
    int ans=0;
    for(auto &it:mp){
        int freq=it.second;
        ans+=freq*(freq-1)/2;
    }
    return ans;
}
int main(){
    // Output: 1
    vector<vector<int>>dominoes={{1,2},{2,1},{3,4},{5,6}};
    // Output: 3
    vector<vector<int>>dominoes2={{1,2},{1,2},{1,1},{1,2},{2,2}};
    cout<<numEquivDominoPairs(dominoes)<<endl;
    cout<<numEquivDominoPairs(dominoes2);
    return 0;
}