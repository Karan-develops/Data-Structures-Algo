// LC - 1146 - Medium - Snapshot Array
#include<iostream>
#include<vector>
using namespace std;
class Solution{
    int snap_id;
    vector<vector<pair<int,int>>>vec;
    public:
    Solution(int length){
        this->snap_id=0;
        vec.resize(length);
        for(int i=0;i<length;i++){
            vec[i].push_back(make_pair(0,0));
        }
    }
    void set(int index,int val){
        vec[index].push_back(make_pair(snap_id,val));
    }
    int snap(){
        return snap_id++;
    }
    int get(int index,int snap_id){
        int start=0,end=vec.size()-1;
        int mid=start+(end-start)/2;
        int ans=0;
        while(start<=end){
            if(vec[index][mid].first<=snap_id){
                ans=vec[index][mid].second;
                start=mid+1;
            } else{
                end=mid-1;
            }
            mid=start+(end-start)/2;
        }
        return ans;
    }
};