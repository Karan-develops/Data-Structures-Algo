// LC - 3531 - Medium - Count Covered Buildings
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int countCoveredBuildings(int n,vector<vector<int>>&buildings){
    unordered_map<int,pair<int,int>>yToMinMaxX;
    unordered_map<int,pair<int,int>>xToMinMaxY;

    for(auto &building:buildings){
        int x=building[0];
        int y=building[1];

        if(!yToMinMaxX.count(x)){
            yToMinMaxX[x]={INT_MAX,INT_MIN};
        }

        if(!xToMinMaxY.count(y)){
            xToMinMaxY[y]={INT_MAX,INT_MIN};
        }

        yToMinMaxX[x].first=min(yToMinMaxX[x].first,y);
        yToMinMaxX[x].second=max(yToMinMaxX[x].second,y);

        xToMinMaxY[y].first=min(xToMinMaxY[y].first,x);
        xToMinMaxY[y].second=max(xToMinMaxY[y].second,x);
    }

    int ans=0;

    for(auto &building:buildings){
        int x=building[0];
        int y=building[1];

        auto &xr=xToMinMaxY[y];
        auto &yr=yToMinMaxX[x];

        if(xr.first<x && x<xr.second && yr.first<y && y<yr.second){
            ans++;
        }
    }

    return ans;
}
int main(){
    // Output: 1
    int n=3;
    vector<vector<int>>buildings={{1,2},{2,2},{3,2},{2,1},{2,3}};
    // Output: 0
    int n2=3;
    vector<vector<int>>buildings2={{1,1},{1,2},{2,1},{2,2}};
    // Output: 1
    int n3=5;
    vector<vector<int>>buildings3={{1,3},{3,2},{3,3},{3,5},{5,3}};
    cout<<countCoveredBuildings(n,buildings)<<endl;
    cout<<countCoveredBuildings(n2,buildings2)<<endl;
    cout<<countCoveredBuildings(n3,buildings3);
    return 0;
}