// LC - 2225 - Medium - Find Players With Zero or One Losses
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
vector<vector<int>> findWinners(vector<vector<int>>&matches){
    unordered_map<int,int>lostMap;
    for(auto &vec:matches){
        lostMap[vec[1]]++;
    }
    vector<int>winVec;
    vector<int>oneLossVec;
    for(auto &vec:matches){
        int winner=vec[0];
        int losser=vec[1];

        if(lostMap[losser]==1){
            oneLossVec.push_back(losser);
        }
        if(lostMap.find(winner)==lostMap.end()){
            winVec.push_back(winner);
            lostMap[winner]=2;
        }
    }
    sort(begin(winVec),end(winVec));
    sort(begin(oneLossVec),end(oneLossVec));

    return {winVec,oneLossVec};
}
int main(){
    // OP - [[1,2,10],[4,5,7,8]]
    vector<vector<int>>nums1={{1,3},{2,3},{3,6},{5,6},{5,7},{4,5},{4,8},{4,9},{10,4},{10,9}};
    // OP - [[1,2,5,6],[]]
    vector<vector<int>>nums2={{2,3},{1,3},{5,4},{6,4}};
    vector<vector<int>>ans1=findWinners(nums1);
    vector<vector<int>>ans2=findWinners(nums2);
    for(auto &it:ans1){
        cout<<'[';
        for(auto &i:it) cout<<i<<",";
        cout<<']';
    }
    cout<<endl;
    for(auto &it:ans2){
        cout<<'[';
        for(auto &i:it) cout<<i<<",";
        cout<<']';
    }
    return 0;
}