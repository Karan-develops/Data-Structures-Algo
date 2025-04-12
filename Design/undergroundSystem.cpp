// LC - 1396 - Medium - Design Underground System
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution{
    // {id -> station,time}
    unordered_map<int,pair<string,int>>checkInMap;
    // {Route -> totalTime,Count}
    unordered_map<string,pair<int,int>>checkOutMap;
    public:
    void checkIn(int id,string stationName,int t){
        checkInMap[id]={stationName,t};
    }
    void checkOut(int id,string stationName,int t){
        auto [entryStation,entryTime]=checkInMap[id];
        string route=entryStation+"_"+stationName;
        int totalTime=t-entryTime;
        checkOutMap[route].first=totalTime;
        checkOutMap[route].second+=1;

        checkInMap.erase(id); // To Save space
    }
    double getAverageTime(string startStation,string endStation){
        string route=startStation+"_"+endStation;
        auto &it=checkOutMap[route];
        return (double)it.first/it.second;
    }
};