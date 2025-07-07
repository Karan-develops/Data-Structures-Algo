// LC - 1353 - Medium - Maximum Number of Events That Can Be Attended
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int maxEvents(vector<vector<int>>&events){
    int n=events.size();

    sort(begin(events),end(events));

    priority_queue<int,vector<int>,greater<>>pq;

    int ans=0;
    int day=events[0][0];
    int i=0;

    while(!pq.empty() || i<n){
        if(pq.empty()){
            day=events[i][0];
        }

        while(i<n && day==events[i][0]){
            pq.push(events[i][1]);
            i++;
        }

        if(!pq.empty()){
            // 1 event attended on this day
            pq.pop();
            ans++;
        }

        day++;

        while(!pq.empty() && pq.top()<day){
            pq.pop();
        }
    }
    return ans;
}
int main(){
    // Output: 3
    vector<vector<int>>events={{1,2},{2,3},{3,4}};
    // Output: 4
    vector<vector<int>>events2={{1,2},{2,3},{3,4},{1,2}};
    cout<<maxEvents(events)<<endl;
    cout<<maxEvents(events2);
    return 0;
}