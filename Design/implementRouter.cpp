// LC - 3508 - Medium - Implement Router
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;
class Design{
    int limit;
    queue<string>q;
    unordered_map<string,vector<int>>packetStore;
    unordered_map<int,vector<int>>destinationTimestamps;
    string makeKey(int src,int dest,int ts){
        return to_string(src)+"_"+to_string(dest)+"_"+to_string(ts);
    }
    public:
    Design(int memoryLimit){
        limit=memoryLimit;
    }
    bool addPacket(int source,int destination,int timestamp){
        string key=makeKey(source,destination,timestamp);

        if(packetStore.find(key)!=packetStore.end()){
            return false;
        }

        if(q.size()>=limit){
            forwardPacket();
        }

        q.push(key);
        packetStore[key]={source,destination,timestamp};
        destinationTimestamps[destination].push_back(timestamp);

        return true;
    }
    vector<int> forwardPacket(){
        if(packetStore.empty()) return {};

        string key=q.front();
        q.pop();

        vector<int>packet=packetStore[key];
        packetStore.erase(key);

        int dest=packet[1];
        destinationTimestamps[dest].erase(destinationTimestamps[dest].begin());

        return packet;
    }
    int getCount(int destination,int startTime,int endTime){
        // unordered_map<int,vector<int>>::iterator it=destinationTimestamps.find(destination);
        auto it=destinationTimestamps.find(destination);
        if(it==destinationTimestamps.end() || it->second.empty()){
            return 0;
        }

        int i=lower_bound(begin(it->second),end(it->second),startTime)-begin(it->second);
        int j=upper_bound(begin(it->second),end(it->second),endTime)-begin(it->second);

        return j-i;
    }
};