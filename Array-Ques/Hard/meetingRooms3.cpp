// LC - 2402 - HARD - Meeting Rooms III
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int mostBooked(int n,vector<vector<int>>&meetings){
    sort(begin(meetings),end(meetings));

    vector<int>roomUsedCount(n,0);
    vector<long long>lastAvailableAt(n,0);

    for(auto &vec:meetings){
        int start=vec[0];
        int end=vec[1];
        bool found=false;

        long long earlyEndRoomTime=LLONG_MAX;
        int earlyEndRoom=0;

        for(int room=0;room<n;room++){
            if(lastAvailableAt[room]<=start){
                found=true;
                lastAvailableAt[room]=end;
                roomUsedCount[room]++;
                break;
            }
            if(lastAvailableAt[room]<earlyEndRoomTime){
                earlyEndRoom=room;
                earlyEndRoomTime=lastAvailableAt[room];
            }
        }

        if(!found){
            lastAvailableAt[earlyEndRoom]+=(end-start);
            roomUsedCount[earlyEndRoom]++;
        }
    }

    int ans=-1;
    int maxUsed=0;
    for(int i=0;i<n;i++){
        if(maxUsed<roomUsedCount[i]){
            maxUsed=roomUsedCount[i];
            ans=i;
        }
    }
    return ans;
}
int main(){
    // Output: 0
    int n=2;
    vector<vector<int>>meetings={{0,10},{1,5},{2,7},{3,4}};
    // Output: 1
    int n2=3;
    vector<vector<int>>meetings2={{1,20},{2,10},{3,5},{4,9},{6,8}};
    cout<<mostBooked(n,meetings)<<endl;
    cout<<mostBooked(n2,meetings2);
    return 0;
}