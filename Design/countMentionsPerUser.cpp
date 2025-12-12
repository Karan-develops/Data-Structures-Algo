// LC - 3433 - Medium - Count Mentions Per User
// Topics -> Array, Math, Sorting, Simulation
#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;
class Design{
    void applyMessageEvent(const vector<string>&event,vector<int>&mentionCount,vector<int>&offlineTime){
        int timeStamp=stoi(event[1]);

        vector<string>ids;

        stringstream ss(event[2]);
        string token;

        while(ss>>token){
            ids.push_back(token);
        }

        for(string &id:ids){
            if(id=="ALL"){
                for(int i=0;i<mentionCount.size();i++){
                    mentionCount[i]++;
                }
            } else if(id=="HERE"){
                for(int i=0;i<mentionCount.size();i++){
                    if(offlineTime[i]==0 || offlineTime[i]+60<=timeStamp){
                        mentionCount[i]++;
                    }
                }
            } else{
                mentionCount[stoi(id.substr(2))]++;
            }
        }
    }
    public:
    vector<int> countMentions(int numberOfUsers,vector<vector<string>>&events){
        vector<int>mentionCount(numberOfUsers);
        vector<int>offlineTime(numberOfUsers);

        auto lambda=[&](vector<string>&v1,vector<string>&v2){
            int t1=stoi(v1[1]);
            int t2=stoi(v2[1]);

            if(t1==t2){
                // comparing 'O' of "OFFLINE" with 'M' of "MESSAGE"
                // OFFLINE should come first
                return v1[0][1]>v2[0][1];
            }

            return t1<t2;
        };

        sort(begin(events),end(events),lambda);

        for(const vector<string> &event:events){
            if(event[0]=="MESSAGE"){
                applyMessageEvent(event,mentionCount,offlineTime);
            } else{
                int timeStamp=stoi(event[1]);
                int userId=stoi(event[2]);
                offlineTime[userId]=timeStamp;
            }
        }

        return mentionCount;
    }
};
int main(){
    // Output: [2,2]
    int numberOfUsers=2;
    vector<vector<string>>events={{"MESSAGE","10","id1 id0"},{"OFFLINE","11","0"},{"MESSAGE","71","HERE"}};
    // Output: [0,1]
    int numberOfUsers2=2;
    vector<vector<string>>events2={{"OFFLINE","10","0"},{"MESSAGE","12","HERE"}};
    return 0;
}